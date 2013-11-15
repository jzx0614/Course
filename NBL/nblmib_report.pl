#!/usr/local/bin/perl
# Subject: Repoert Generator for MIB Object AutoChecker
# Programmer: Zhixuan Jian, Elia Chen
# Copyright (C)2006 ITRI-NCTU Network Benchmarking Laboratory
#
# (C)2006 ICL, Industrial Technology Research Institude
# ALL RIGHTS RESERVED  Hsinzhu Taiwan
#
# Usage: nblmib_report work_dir filename

use Tk; 
use Tk::Dialog;

if($ARGC < 2) { print "Usage: nblmib_report work_dir filename"; }
$work_dir=$ARGV[0];
$filename=$ARGV[1];

#$config_name="nblmib.ini";

sub tk_die {
    my $message = shift; 
    my $mw = new MainWindow; 
    $mw->Dialog(-text => $message, -title => 'File Error')->Show();  
} 

sub main {
    #read_config();
    read_log();
    Fill_xml();
}

sub get_date {
    my ($sec,$min,$hour,$day,$mon,$year)=localtime(time);
    $mon++;
    if (length ($mon) == 1) {$mon = '0'.$mon;}
    if (length ($day) == 1) {$day = '0'.$day;}
    if (length ($hour) == 1) {$hour = '0'.$hour;}
    if (length ($min) == 1) {$min = '0'.$min;}
    if (length ($sec) == 1) {$sec = '0'.$sec;}
    $year+=1900;
    my $alltime="$year-$mon$day";
}

#sub read_config
#{
#    open(CONFIG,"$config_name");
#    while(my $line = <CONFIG>)
#    {
#        @buf=split(/=/, $line);
#        $buf[1]=~s/\\/\//g;
#        $buf[1]=~s/\r//g;
#        chomp($buf[1]);
#        if($buf[0] eq "REPORT_DST") { $work_dir=$buf[1]; }
#    }
#    close(CONFIG);
#}

sub read_log {
    $now_date=get_date();
    open(LOG_FILE,"$work_dir/$filename.csv") || tk_die "$work_dir/$filename.csv $!\n";
    $g_id=0;
    while(my $line = <LOG_FILE>) {
        chomp $line;
        @buf=split(/,/, $line);
        if($#buf==0) {
            $g_id++;
            push (@g_name,$buf[0]);
        }
        elsif($#buf >= 2) {
            push (@g_type,$g_id);
            push (@name,$buf[0]);
            push (@access_type,$buf[1]);
            push (@result,$buf[2]);
            if($#buf == 3) {push (@comment,$buf[3]);}
            else {push (@comment,"");}
        }
    }
    close(LOG_FILE);
}

sub Fill_xml()
{    
    open(XML_FILE,"> $work_dir/$filename.xls") || tk_die "$filename.csv $!\n";
    xml_header();
    xml_style();
    sheet_init();
    for($i=0;$i<=$#g_name;$i++) {
        print XML_FILE "   <Row></Row>\n".
        "   <Row>\n".
        xml_format("Group ".chr($i+65).": MIB Objects: ".$g_name[$i],"ss:StyleID='group_name'").
        "   </Row>\n".
        "   <Row></Row>\n";
        "   <Row>\n".
        fill_group_table($i+1);
        "   </Row>\n";
    }
    sheet_end();
    close(XML_FILE);
}

sub xml_header {
    print XML_FILE
    "<?xml version=\"1.0\"?>\n".
    "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n".
    "xmlns:o=\"urn:schemas-microsoft-com:office:office\"\n".
    "xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n".
    "xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n".
    "xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n";
}

sub xml_style {
    print XML_FILE
    " <Styles>\n".
    "  <Style ss:ID='Default' ss:Name='Normal'>\n".
    "   <Alignment ss:Vertical='Bottom'/>\n".
    "   <Borders/>\n".
    "   <Font ss:FontName=\"Times New Roman\" x:Family=\"Roman\"/>\n".
    "   <Interior/>\n".
    "   <NumberFormat/>\n".
    "   <Protection/>\n".
    "  </Style>\n".
    "  <Style ss:ID='group_name'>\n".
    "   <Font ss:FontName='Times New Roman' x:Family='Roman' ss:Bold='1'/>\n".
    "  </Style>\n".
    "  <Style ss:ID='group_title'>\n".
    "   <Borders>\n".
    "    <Border ss:Position='Bottom' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Left' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Right' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Top' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "   </Borders>\n".
    "   <Font ss:FontName='Times New Roman' x:Family='Roman'/>\n".
    "   <Interior ss:Color='#C0C0C0' ss:Pattern='Solid'/>\n".
    "  </Style>\n".
    "  <Style ss:ID='blue'>\n".
    "   <Alignment ss:Horizontal='Left' ss:Vertical='Center'/>\n".
    "   <Borders>\n".
    "    <Border ss:Position='Bottom' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Left' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Right' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Top' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "   </Borders>\n".
    "   <Font ss:FontName='Times New Roman' x:Family='Roman'/>\n".
    "   <Interior ss:Color='#99CCFF' ss:Pattern='Solid'/>\n".
    "  </Style>\n".
    "  <Style ss:ID='green'>\n".
    "   <Alignment ss:Horizontal='Left' ss:Vertical='Center'/>\n".
    "   <Borders>\n".
    "    <Border ss:Position='Bottom' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Left' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Right' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Top' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "   </Borders>\n".
    "   <Font ss:FontName='Times New Roman' x:Family='Roman'/>\n".
    "   <Interior ss:Color='#CCFFCC' ss:Pattern='Solid'/>\n".
    "  </Style>\n".
    "  <Style ss:ID='table_bold'>\n".
    "   <Alignment ss:Horizontal='Center' ss:Vertical='Center'/>\n".
    "   <Borders>\n".
    "    <Border ss:Position='Bottom' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Left' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Right' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Top' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "   </Borders>\n".
    "   <Font ss:FontName='Times New Roman' x:Family='Roman' ss:Bold='1'/>\n".
    "  </Style>\n".
    "  <Style ss:ID='table_bold_color'>\n".
    "   <Alignment ss:Horizontal='Center' ss:Vertical='Center'/>\n".
    "   <Borders>\n".
    "    <Border ss:Position='Bottom' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Left' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Right' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Top' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "   </Borders>\n".
    "   <Font ss:FontName='Times New Roman' x:Family='Roman' ss:Bold='1' ss:Color='#800000'/>\n".
    "  </Style>\n".
    "  <Style ss:ID='table_default'>\n".
    "   <Alignment ss:Horizontal='Left' ss:Vertical='Center' ss:WrapText='1'/>\n".
    "   <Borders>\n".
    "    <Border ss:Position='Bottom' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Left' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Right' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "    <Border ss:Position='Top' ss:LineStyle='Continuous' ss:Weight='1'/>\n".
    "   </Borders>\n".
    "   <Font ss:FontName='Times New Roman' x:Family='Roman'/>\n".
    "  </Style>\n".
    " </Styles>    \n".
    "}\n";
}

sub sheet_init {
    print XML_FILE
    "<Worksheet ss:Name='Sheet1'>\n".
    "  <Table x:FullColumns='1' x:FullRows='1' ss:DefaultRowHeight='13.2'>\n".
    "   <Column ss:AutoFitWidth='0' ss:Width='25.8'/>\n".
    "   <Column ss:Width='160'/>\n".
    "   <Column ss:Width='80'/>\n".
    "   <Column ss:Index='5'  ss:Width='60'/>\n".
    "   <Column ss:AutoFitWidth='0' ss:Width='190'/>\n";
}

sub sheet_end {
    print XML_FILE
    "  </Table>\n".
    " </Worksheet>\n".
    "</Workbook>\n";
}

sub xml_format {
    my ($w_string,$Style)=@_;
    $out_str="       <ss:Cell ".$Style.">".
             "<ss:Data ss:Type='String'>".$w_string."</ss:Data>".
             "</ss:Cell>\n";
    return $out_str;
}

sub fill_group_table() {
    my $g_id=$_[0];
    @first_col=("","Name","To Observe","Result","Access Type","Comment");
    print XML_FILE "   <Row>\n";
    foreach (@first_col) { print XML_FILE xml_format($_,"ss:StyleID='group_title'"); }
    print XML_FILE "   </Row>\n";
    
    $count=1;
    for(my $j=0;$j<=$#name;$j++) {
        if($g_type[$j] == $g_id) {
            if($result[$j] eq "Passed"){$style="ss:StyleID='table_bold'";}
            else{$style="ss:StyleID='table_bold_color'";}
            print XML_FILE "   <Row>\n".
            xml_format(chr($g_id+64).".".$count++,"ss:StyleID='blue'").
            xml_format("$name[$j]","ss:StyleID='blue'").
            xml_format("Accassible Object","ss:StyleID='green'").
            xml_format("$result[$j]",$style).
            xml_format("$access_type[$j]","ss:StyleID='table_default'").
            xml_format("$comment[$j]","ss:StyleID='table_default'").
            "   </Row>\n";
        }
    }
}

print "\nGenerating XML summary report: $filename.xlt\n";
main();
