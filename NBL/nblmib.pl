#!/usr/local/bin/perl
# Subject: NBL MIB Object AutoChecker
# Programmer: Zhixuan Jian, Elia Chen
# Copyright (C)2006 ITRI-NCTU Network Benchmarking Laboratory
#
# (C)2006 ICL, Industrial Technology Research Institude
# ALL RIGHTS RESERVED  Hsinzhu Taiwan


$config_name="nblmib.ini";

sub main {
    read_config();

    create_log();
    for($group_index=0;$group_index<=$#mib;$group_index++) {
        output_group_msg($group_index);
        if(translate_table($mib[$group_index],$test_group[$group_index])) {
             read_match($mib[$group_index],$test_group[$group_index]);    
             write_test($mib[$group_index]);
        }
        output_log_msg();
    }
    close_log();

    my $xml_pos=index($file_name, ".csv");
    my $xml_file=substr($file_name,0,$xml_pos);

    system("$reporter $report_dst $xml_file");
}

sub get_date {
    my ($sec,$min,$hour,$day,$mon,$year)=localtime(time);
    $mon++;
    if (length ($mon) == 1) {$mon = '0'.$mon;}
    if (length ($day) == 1) {$day = '0'.$day;}
    $year+=1900;
    my $alltime="$year-$mon$day";
}

sub errormsg {
    $e_string=$_[0];
    print $e_string."\n";
    print "Plesase Press Ctrl+C to exit\n";
    $error=<STDIN>;
}

sub printmsg {
    $str=$_[0];
    print LOG_FILE $str;
    print $str;
}

sub create_log {
    $Iteration=0;
    do {
        $file_name="mib_".$model."_MIBAuto_all_".++$Iteration."_".get_date().".csv";
    } while(-e "$report_dst/$file_name");
    
    if(!(-e $logs_dst)){ mkdir ($logs_dst,755 ) || errormsg "Make logs dir fail\n";}
    if(!(-e $report_dst)){ mkdir ($report_dst,755 ) || errormsg "Make reports dir fail\n";}
    $log_file=$logs_dst."/nblmib_".$Iteration."_".get_date().".log" ;
    $read_log=$logs_dst."/nblmib_".$Iteration."_".get_date()."_r.log" ;
    $write_log=$logs_dst."/nblmib_".$Iteration."_".get_date()."_w.log";
    
    open(CSV, "> $report_dst/$file_name") || errormsg "Generating CSV fail: $_";
    open(READ_LOG, "> $read_log") || errormsg "Open Read_LOG fail: $_";
    open(WRITE_LOG, "> $write_log") || errormsg "Open Write_LOG fail: $_";
    open(LOG_FILE, "> $log_file") || errormsg "Open LOG_FILE fail: $_";

    print LOG_FILE get_date()."\n";
}

sub close_log {
    close(CSV);
    close(READ_LOG);
    close(WRITE_LOG);
    close(LOG_FILE);
}

sub read_config {
    open(CONFIG,"$config_name") || errormsg "Open Config Error: $_\n";
    while(my $line = <CONFIG>) {
        $comm_pos=index($line,"#");
        if($comm_pos >= 0) {
            $temp = substr($line,0,$comm_pos);
            $line = $temp;
        }
        @buf=split(/=/, $line);
        $buf[1]=~s/\\/\//g;
        $buf[1]=~s/\r//g;
        chomp($buf[1]);
        if($buf[0] eq "LOGS_DST") {$logs_dst=$buf[1];}
        elsif($buf[0] eq "REPORT_DST") {$report_dst=$buf[1];}
        elsif($buf[0] eq "DUT_MODEL") {$model=$buf[1];}
        elsif($buf[0] eq "DUT_IPADDR") {$ip=$buf[1];}
        elsif($buf[0] eq "SNMP_VERSION") {$version=($buf[1]==2)?"2c":$buf[1];}
        elsif($buf[0] eq "COMMUNITY") {$comm=$buf[1];}
        elsif($buf[0] eq "REPORTER") {$reporter=$buf[1];}
        elsif($buf[0] eq "OID_LABEL") {
            @test_list=split(/\s+/, $buf[1]);    
            foreach (@test_list) {
                my $left = index($_, ":");
                if($left == -1) {
                    push (@mib,"ALL");
                    push (@test_group,$_);
                }
                else {
                    push (@mib,substr($_,0,$left));
                    push (@test_group,substr($_,$left+1));
                }
            }
        }
        elsif($buf[0] eq "USER_NAME") {}
        elsif($buf[0] eq "AUTH_PROTOCOL") {}
        elsif($buf[0] eq "AUTH_PASSWORD" ) {}
        elsif($buf[0] eq "PRIV_PROTOCOL" ) {}
        elsif($buf[0] eq "PRIV_PASSWORD" ) {}
    }
    close(CONFIG);
    check_ini_file();
}

sub check_ini_file {
    if($version eq "") { $error_str.="SNMP_VERSION is empty.\n"; }
    if($ip eq "") { $error_str.="DUT_IPADDR is empty.\n"; }
    if($comm eq "") { $error_str.="COMMUNITY is empty.\n"; }
    if($test_group[0] eq "") { $error_str.="OID_LABEL is empty.\n"; }
    
    if($error_str ne "") { errormsg $error_str; }
    
}

sub output_group_msg {
    $group_index=$_[0];

    print CSV "\n".$mib[$group_index]." ".$test_group[$group_index]."\n\n";
    printmsg  "\n".$mib[$group_index]." ".$test_group[$group_index]."\n\n";
}

sub output_log_msg {
    if($pre_oid eq " " && $groupmesg ne " "){ printmsg "$groupmesg\n"; }
            
    for($i=0;$i<=$#read_table;$i++) {
        if($read_table[$i] eq 'R') {
            my $temp = sprintf ("%-35s",$OID_table[$i]);
            print    CSV    "$temp,";
            printmsg    "$temp";
            if($write_table[$i] eq 'W') {
                print CSV "Read-write,$result_write{$OID_table[$i]}";
                printmsg  "Read-write : $result_write{$OID_table[$i]}";
            }
            elsif($create_table[$i] eq 'C') {
                print CSV "Read-create,$result_read{$OID_table[$i]}";
                printmsg  "Read-create: $result_read{$OID_table[$i]}";
            }
            else {
                print CSV "Read-only,$result_read{$OID_table[$i]}";
                printmsg  "Read-only  : $result_read{$OID_table[$i]}";
            }
            if(exists $comment_table{$OID_table[$i]}) {
                $comment_table{$OID_table[$i]} =~ s/\n/ /g;
                printmsg  "\t$comment_table{$OID_table[$i]}\n";
                
                #$comment_table{$OID_table[$i]} =~ s/\n/&#10;/g ; 
                print CSV ",$comment_table{$OID_table[$i]}\n";
            }
            else {
                print CSV "\n";
                printmsg "\n";
            }
        }
        if($pre_oid eq $OID_table[$i] && $groupmesg ne " "){ printmsg "\n$groupmesg\n"; }
    }
}

sub translate_table {
    my ($mib_name,$label) = @_;
    $cmd_string ="snmptranslate -Tp -Lo -m $mib_name -IR $label 2>&1";
    open(TRANS, "$cmd_string |");

    @read_table = ();
    @write_table = ();
    @create_table = ();
    @OID_table = ();
    
    #print snmptranslate error msg;
    my $line = <TRANS>;
    if($line !~ /\+--/) {
        #printmsg "\n$cmd_string\n\n";
        do { printmsg $line; } while ($line=<TRANS>);
        return 0;
    }
    
    while(my $line = <TRANS>) {
        @buf=split(/\s+/,$line);
        $start=$#buf;
        for($start=0;$start<$#buf;$start++) {
            last if( $buf[$start] eq "+--");
        }
        next if($start == $#buf);
        push (@create_table, substr($buf[$start+1], 0, 1));
        push (@read_table, substr($buf[$start+1], 1, 1));
        push (@write_table, substr($buf[$start+1], 2, 1));
        push (@type_table, $buf[$start+2]);
        my $left = index($buf[$start+3], "(");
        push (@OID_table,substr($buf[$start+3],0,$left));
    }
    close(TRANS);
    return 1;
}

sub read_match {
    my ($mib_name,$label) = @_;
    $cmd_string="snmpwalk -Oqes -Lo -m $mib_name -c $comm -v $version $ip $label 2>&1";
    open(WALK, "$cmd_string | ") || errormsg ("SNMPWALK Error");    
    print READ_LOG "\n$cmd_string\n\n";
    $pre_oid=" ";
    $groupmesg=" ";

    while(my $line= <WALK>) {
        print READ_LOG $line;
        chomp $line;
        if($line =~ /^([\w\.\d]+): /) {
            $groupmesg = "$line\n";
            $error_name=$1;
            
            $flag=0;
            if($error_name =~ /(\w+)\./) {
                foreach $oid (@OID_table) {
                    if($1 eq $oid) {
                        $flag=1;
                        $comment_table{$oid}= $line;                        
                    }
                }
            }
            if($flag == 0 ) {
                if($pre_oid eq " ") { $walked_flag=1; }
                else { $walked_flag=0; }
                foreach $oid (@OID_table) {
                    if($walked_flag) { $comment_table{$oid}=$line; }                    
                    if($oid eq $pre_oid) { $walked_flag=1; }
                }
            }
        }
        else {
            if($line =~ /(\w+)\.([\d|\.]+) (.+)/g) {
                $walk_table{"$1"}="$1.$2";
                $value_table{"$1"}=$3;
                $pre_oid=$1;
            }
#            $div_pos   = index ($line," ");
#            $buf[0]    = substr($line,0,$div_pos);
#    
#            $temp_num  = index ($buf[0],".");
#            if($temp_num==-1){$oid_name  = $buf[0];}
#            else         {$oid_name  = substr($buf[0], 0, $temp_num);}
#            
#            
#            $walk_table{"$oid_name"}=$buf[0];
#            $value_table{"$oid_name"} = substr($line,$div_pos+1);    
            
        }
    }    
    close(WALK);
    
    for($line_index=0;$line_index<=$#read_table;$line_index++) {
        if($read_table[$line_index] eq 'R') {
            if (exists $walk_table{$OID_table[$line_index]}) {
                if(exists $comment_table{$OID_table[$line_index]}) {
                    $result_read{$OID_table[$line_index]}="Failed*";
                }
                else {$result_read{$OID_table[$line_index]}="Passed";}
            }
            else {
                $result_read{$OID_table[$line_index]}="Failed";
                if(!(exists $comment_table{$OID_table[$line_index]})) {
                    $comment_table{$OID_table[$line_index]}="No such object.";
                }
            }
        }
    }
}

sub write_test {
    my $mib_name = $_[0];
    
    for($line_index=0;$line_index<=$#read_table;$line_index++) {
        if($write_table[$line_index] eq 'W') {
            if(exists $walk_table{$OID_table[$line_index]}) {

                $set_str="$walk_table{$OID_table[$line_index]} = $value_table{$OID_table[$line_index]} ";
    #            $g_cmd_string="snmpget -Oes -Lo -m $mib_name -c $comm -v $version $ip $set_str 2>&1"            
    #            open(GET, "$w_cmd_string |") || errormsg ("SNMPGET Error");
    #            my $line=<>
    #            close(GET);

                $w_cmd_string="snmpset -Oqes -Lo -m $mib_name -c $comm -v $version $ip $set_str 2>&1";
                print WRITE_LOG "\n$w_cmd_string\n";
                open(SET, "$w_cmd_string |") || errormsg ("SNMPSET Error");
                my $line = <SET>;
                #print WRITE_LOG $line;
                #chomp $line;
                #my @buf=split(/\s+/,$line);            
                #$temp_num = index ($buf[0],".");
                #$oid_name= substr($buf[0], 0, $temp_num);
                #$set_table{"$oid_name"}="$buf[1]";
                
                if($line =~ /$walk_table{$OID_table[$line_index]}/ && $line !~ /:/) {
                    print WRITE_LOG "$line";
#                    printmsg "$line";
#                    if( $line =~ /^(\w+)\./g ) {
#                        $oid_name=$1;
#                        printmsg "$1 ";
#                    }
#                    if( $line =~ /\d+\s(.+)/g) {
#                        $set_table{"$oid_name"}=$1;
#                        printmsg "$1\n";
#                    }
                    if( $line =~ /(\w+)\.[\d\.]+ (.+)/g) {
                        $set_table{"$1"}=$2;
                    }
                }
                else {
                    do {
                        print WRITE_LOG "$line";
                        $comment_table{$OID_table[$line_index]}.= $line;                
                    } while ($line = <SET>);
                }
            
            close(SET);                    
            }
        }
    }
    
    for($line_index=0;$line_index<=$#read_table;$line_index++) {
        if($write_table[$line_index] eq 'W') {
            if(exists $set_table{$OID_table[$line_index]}) {
                $result_write{$OID_table[$line_index]}="Passed";
            }
            else {
                $result_write{$OID_table[$line_index]}="Failed";
            }
        }
    }
}

main();
print "Press any key to close the program...";
<>;
