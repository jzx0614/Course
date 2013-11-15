#
while (1)
    set dep_num = `awk '{print $1}' file3 | tail -1`
    set peo_num = `awk '{print $1}' file2 | tail -1`
    echo    "(1) 新增"
    echo    "(2) 尋找"
    echo    "(3) 刪除"
    echo    "(4) 修改"
    echo    "(5) 列印"
    echo    "(6) 部門人事成本"
    echo -n "請輸入一個數: "
    set chose = $<
    switch ($chose)
    case 1:
	clear;cat file1
	echo -n "部門(編號): " ;set dep   = $<
	echo -n "姓名      : " ;set name  = $<
	echo -n "出生日期  : " ;set bir   = $<
	echo -n "薪資      : " ;set money = $<
	@ peo_num = $peo_num + 1
	awk -v dep=$dep -v peo_num=$peo_num \
	'(dep==$1) {print $0 "\t" peo_num}(dep!=$1){print}' file3 > temp
	cat temp > file3    &&	rm temp  ;clear
	echo "$peo_num  $name  $bir  $money" >> file2 && echo 新增完成
    breaksw
    case 2:
	echo -n "請輸入人員編號: "
	set p_num = $<
	if ( $p_num < 10 && $p_num !~ [0]* || $p_num > $peo_num) then
	    echo 沒有這個人員編號
	    continue 
	endif
	set dep = (`grep $p_num file3`) ; clear
	echo "部門   編號   姓名   出生日期    薪資"
	awk -v dep=$dep[1] '(dep==$1){printf ("%s   ",$2)}' file1
	awk -v p_num=$p_num '(p_num==$1){print}' file2
    breaksw
     case 3:
	echo -n "請輸入人員編號: "
          set p_num = $<
          if ( $p_num < 10 && $p_num !~ [0]* || $p_num > $peo_num) then
             echo 沒有這個人員編號
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
	clear;cat temp > file2    &&  rm temp && echo 刪除完成 
      breaksw
      case 4:
                echo -n "請輸入人員編號: "
                set p_num = $<
                if ( $p_num < 10 && $p_num !~ [0]* || $p_num > $peo_num) then
                    echo 沒有這個人員編號
                    continue
                endif
	awk -v p_num=$p_num '(p_num==$1){print}' file2
                echo -n "姓名      : " ;set name  = $<
                echo -n "出生日期  : " ;set bir   = $<
                echo -n "薪資      : " ;set money = $<
                set NR = `awk  -v p_num=$p_num '(p_num==$1){print NR}' file2`
                @ front =  $NR - 1
                head -n $front file2 > temp
                echo "$p_num   $name  $bir  $money" >> temp
	awk -v row=$NR '(row+1<=NR){print}' file2 >> temp
	clear;cat temp >file2 && rm temp && echo 修改完成 
        breaksw
    case 5:
	echo -n "(A)ALL (B)Single: "
	set c = $< ; clear
	if($c == A) then
	    echo "部門   編號   姓名   出生日期    薪資"
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
              echo -n "請輸入部門編號: "
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
	    echo $money $num "元"
	end
    breaksw
    default:
	breaksw
    endsw 
end

