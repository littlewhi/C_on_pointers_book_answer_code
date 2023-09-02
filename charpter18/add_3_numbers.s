.text
.global func_ret_int
func_ret_int:
    #edi, esi, edx
    mov $0, %eax
    add %edi, %eax
    add %esi, %eax
    add %edx, %eax
    ret
