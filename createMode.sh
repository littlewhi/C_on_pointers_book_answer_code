
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
    return
fi

rootdir='/home/book/gitrepo/c_on_pointers_ac'
if [ -d $1 ]
then
    echo "destation directory is $1"
else
    mkdir $1
fi
cd $1   #go into destination directory

cat $rootdir/template_make > makefile

#创建头文件
touch a.h
echo "#ifndef _A_H_" > a.h
echo "#define _A_H_" >> a.h
echo "" >> a.h
echo "#include <stdio.h>" >> a.h
echo "#include <stdlib.h>" >> a.h
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
    fi
    
    echo "\\" >> makefile
    echo -e -n "\tcoding$i.o" >> makefile    #依赖文件写入make文件
    echo "void a$i( void );" >> a.h   #源文件的入口函数写入头文件
done

#收尾make文件
echo "" >> makefile
echo -e '\t$(CC) $(OPTION) -o test $^ $(BEHIND)' >> makefile

#收尾头文件
echo "" >> a.h
echo "#endif" >> a.h

########################################

#构造main.c文件

echo "#include \"a.h\"" > main.c
echo "" >> main.c
echo "typedef void( *fp )( void );" >> main.c
echo "static const fp func_table[] = {" >> main.c
echo -n -e "\tNULL, " >> main.c

i=1
for(( i = 1; i <= $2; i++ ))
do 
    
    if [ $((i % 3)) -eq 0 ]
    then
        echo "" >> main.c
        echo -e -n "\t" >> main.c
    fi
    if [ $i -eq $2 ]
    then
        echo "a$i" >> main.c
    else
        echo -n "a$i, " >> main.c
    fi 
done

# main.c收尾
echo "};" >> main.c
cat $rootdir/template_code >> main.c
