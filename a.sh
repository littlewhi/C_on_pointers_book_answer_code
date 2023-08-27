
dir='charpter1 charpter2 charpter4 charpter5 charpter6'

for d in $dir
do
    cd $d
    touch main.c
    cat ../template_code > main.c
    touch a.h
    cat ../template_header > a.h
    touch makefile 
    cat ../template_make > makefile
    cd ..
done