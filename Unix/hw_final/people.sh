#
while (1)
    set dep_num = `awk '{print $1}' file3 | tail -1`
    set peo_num = `awk '{print $1}' file2 | tail -1`
    echo    "(1) �s�W"
    echo    "(2) �M��"
    echo    "(3) �R��"
    echo    "(4) �ק�"
    echo    "(5) �C�L"
    echo    "(6) �����H�Ʀ���"
    echo -n "�п�J�@�Ӽ�: "
    set chose = $<
    switch ($chose)
    case 1:
	clear;cat file1
	echo -n "����(�s��): " ;set dep   = $<
	echo -n "�m�W      : " ;set name  = $<
	echo -n "�X�ͤ��  : " ;set bir   = $<
	echo -n "�~��      : " ;set money = $<
	@ peo_num = $peo_num + 1
	awk -v dep=$dep -v peo_num=$peo_num \
	'(dep==$1) {print $0 "\t" peo_num}(dep!=$1){print}' file3 > temp
	cat temp > file3    &&	rm temp  ;clear
	echo "$peo_num  $name  $bir  $money" >> file2 && echo �s�W����
    breaksw
    case 2:
	echo -n "�п�J�H���s��: "
	set p_num = $<
	if ( $p_num < 10 && $p_num !~ [0]* || $p_num > $peo_num) then
	    echo �S���o�ӤH���s��
	    continue 
	endif
	set dep = (`grep $p_num file3`) ; clear
	echo "����   �s��   �m�W   �X�ͤ��    �~��"
	awk -v dep=$dep[1] '(dep==$1){printf ("%s   ",$2)}' file1
	awk -v p_num=$p_num '(p_num==$1){print}' file2
    breaksw
     case 3:
	echo -n "�п�J�H���s��: "
          set p_num = $<
          if ( $p_num < 10 && $p_num !~ [0]* || $p_num > $peo_num) then
             echo �S���o�ӤH���s��
             continue
          endif
	set dep = (`grep $p_num file3`)
	set index = 2
	foreach id ($dep[2-])
	    if($p_num == $id) then
	      @ front =  $index - 1
	      @ back	=  $index + 1
	    set dep = ($dep[1-$front] $dep[$back-$#dep])
	    endif
	    @ index++
	end
          set NR = `awk  -v p_num=$dep[1] '(p_num==$1){print NR}' file2`
          @ front =  $NR - 1
          head -n $front file3 > temp
	echo $dep >> temp
	awk -v row=$NR '(row+1<=NR){print}' file3 >> temp
	cat temp > file3 && rm temp 
	awk -v p_num=$p_num '(p_num!=$1){print}' file2 > temp
	clear;cat temp > file2    &&  rm temp && echo �R������ 
      breaksw
      case 4:
                echo -n "�п�J�H���s��: "
                set p_num = $<
                if ( $p_num < 10 && $p_num !~ [0]* || $p_num > $peo_num) then
                    echo �S���o�ӤH���s��
                    continue
                endif
	awk -v p_num=$p_num '(p_num==$1){print}' file2
                echo -n "�m�W      : " ;set name  = $<
                echo -n "�X�ͤ��  : " ;set bir   = $<
                echo -n "�~��      : " ;set money = $<
                set NR = `awk  -v p_num=$p_num '(p_num==$1){print NR}' file2`
                @ front =  $NR - 1
                head -n $front file2 > temp
                echo "$p_num   $name  $bir  $money" >> temp
	awk -v row=$NR '(row+1<=NR){print}' file2 >> temp
	clear;cat temp >file2 && rm temp && echo �ק粒�� 
        breaksw
    case 5:
	echo -n "(A)ALL (B)Single: "
	set c = $< ; clear
	if($c == A) then
	    echo "����   �s��   �m�W   �X�ͤ��    �~��"
	    set i = 1
              while ($i <= $dep_num)
                    set dep = (`awk -v d=$i '(d==$1){print}' file3`)
                    awk -v d=$i '(d==$1){print $2}' file1
	        foreach id ($dep[2-])
	        awk -v id=$id '(id==$1){print}' file2
	    end
                    @ i++
                    end
	    sleep 2
	else if($c == B) then
	    clear;cat file1
              echo -n "�п�J�����s��: "
             set d = $<
              set dep = (`awk -v d=$d '(d==$1){print}' file3`)
              awk -v d=$d '(d==$1){print $2}' file1
              foreach id ($dep[2-])
		    awk -v id=$id '(id==$1){print}' file2
              end
	endif
    breaksw
    case 6:
	clear ; set i = 1
	while ($i <= $dep_num)
	    set dep = (`awk -v d=$i '(d==$1){print}' file3`)
	    set money = (`awk -v d=$i '(d==$1){print}' file1`)
	    set num = 0
	    foreach id ($dep[2-])
	    set tmp = `awk -v id=$id '(id==$1){print $4}' file2`
	    @ num += $tmp
	    end
	    @ i++
	    echo $money $num "��"
	end
    breaksw
    default:
	breaksw
    endsw 
end

