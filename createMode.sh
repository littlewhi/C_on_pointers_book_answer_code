
#    cd $1
#    touch main.c
#    cat ../template_code > main.c
#    touch a.h
#    cat ../template_header > a.h
#    touch makefile 
#    cat ../template_make > makefile

if [ $# -ne 2 ]
then
    echo "Usage: $0 <directory> <number>"
    echo "Example $0 charpter1 4"
    exit
fi

rootdir='/home/book/gitrepo/c_on_pointers_ac'

cd $1   #go into destination directory

cat $rootdir/template_make > makefile
cat $rootdir/template_code > main.c

#创建头文件
touch a.h
echo "#ifndef _A_H_" >> a.h
echo "#define _A_H_" >> a.h
echo "" >> a.h
echo "#include <stdio.h>" >> a.h
echo "" >> a.h

for(( i = 1; i <= $2; i++ ))
do
    filename="coding$i.c"
    if [ -e $filename ]
    then
        echo "exist"
    else
        touch $filename #创建源文件 
        echo "#include \"a.h\"" >> $filename
        echo "" >> $filename
        echo "void a$i( void )" >> $filename
        echo -e "{\n\n}" >> $filename
        
        #入口函数写入main文件
        echo -e "\t\tcase '$i':" >> main.c
        echo -e "\t\t\ta$i();" >> main.c
        echo -e "\t\t\tbreak;" >> main.c

        echo "\\" >> makefile
        echo -e -n "\tcoding$i.o" >> makefile    #依赖文件写入make文件
        echo "void a$i( void );" >> a.h   #源文件的入口函数写入头文件
    fi
done

#收尾make文件
echo "" >> makefile
echo -e '\t$(CC) $(OPTION) -o test $^ $(BEHIND)' >> makefile

#收尾main.c文件
echo -e "\t\tdefault:" >> main.c
echo -e "\t\t\tputs( \"Unkonw options\" );" >> main.c
echo -e "\t\t\tbreak;" >> main.c
echo -e "\t}" >> main.c
echo "}" >> main.c

#收尾头文件
echo "" >> a.h
echo "#endif" >> a.h

########################################