dirs=$(ls)
curdir=$(pwd)
cmdname='/home/book/gitrepo/c_on_pointers_ac/createMode.sh'

for dir in $dirs
do
    if[ -d $dir ] && [ "$dir" != "charpter2" ]
    then
        cd $dir
        cnt=$(ls | grep 'coding[0-9]*\.c' -c)
        echo "There are $cnt code files in $dir"
        . cmdname . $cnt
    fi
done

echo "$cnt
