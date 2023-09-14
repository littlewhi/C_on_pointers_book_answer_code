dirs=$(ls)

for dir in $dirs
do
    if [ -d "$dir" ]
    then
        cd $dir
        make clean
        cd ..
    fi
done