#/bin/csh

set path_list=(`echo $PATH|awk -F: 'BEGIN{i=0}{while (++i<=NF) printf("%s ",$i)}'`)
foreach filename ($*)
    if (!(-d $filename)) then
	echo $filename "is not paths"
	continue
    endif
    foreach path_l ($path_list)
	if ( $path_l == $filename) then
	    echo $filename is in paths list
	    break;continue
	endif
    end
    echo $filename is not in paths list
end

