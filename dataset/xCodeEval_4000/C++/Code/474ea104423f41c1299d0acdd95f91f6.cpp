__asm__(R"( 
        .file   "B_odd_subarrays.cpp"
    .text
    .section .rdata,"dr"
_ZStL19piecewise_construct:
    .space 1
_ZStL13allocator_arg:
    .space 1
_ZStL6ignore:
    .space 1
.lcomm _ZStL8__ioinit,1,1
    .align 4
_ZN9__gnu_cxxL21__default_lock_policyE:
    .long   2
_ZStL10defer_lock:
    .space 1
_ZStL11try_to_lock:
    .space 1
_ZStL10adopt_lock:
    .space 1
    .align 4
_ZNSt15regex_constantsL5icaseE:
    .long   1
    .align 4
_ZNSt15regex_constantsL6nosubsE:
    .long   2
    .align 4
_ZNSt15regex_constantsL8optimizeE:
    .long   4
    .align 4
_ZNSt15regex_constantsL7collateE:
    .long   8
    .align 4
_ZNSt15regex_constantsL10ECMAScriptE:
    .long   16
    .align 4
_ZNSt15regex_constantsL5basicE:
    .long   32
    .align 4
_ZNSt15regex_constantsL8extendedE:
    .long   64
    .align 4
_ZNSt15regex_constantsL3awkE:
    .long   128
    .align 4
_ZNSt15regex_constantsL4grepE:
    .long   256
    .align 4
_ZNSt15regex_constantsL5egrepE:
    .long   512
    .align 4
_ZNSt15regex_constantsL12__polynomialE:
    .long   1024
    .align 4
_ZNSt15regex_constantsL13match_defaultE:
    .space 4
    .align 4
_ZNSt15regex_constantsL13match_not_bolE:
    .long   1
    .align 4
_ZNSt15regex_constantsL13match_not_eolE:
    .long   2
    .align 4
_ZNSt15regex_constantsL13match_not_bowE:
    .long   4
    .align 4
_ZNSt15regex_constantsL13match_not_eowE:
    .long   8
    .align 4
_ZNSt15regex_constantsL9match_anyE:
    .long   16
    .align 4
_ZNSt15regex_constantsL14match_not_nullE:
    .long   32
    .align 4
_ZNSt15regex_constantsL16match_continuousE:
    .long   64
    .align 4
_ZNSt15regex_constantsL16match_prev_availE:
    .long   128
    .align 4
_ZNSt15regex_constantsL14format_defaultE:
    .space 4
    .align 4
_ZNSt15regex_constantsL10format_sedE:
    .long   256
    .align 4
_ZNSt15regex_constantsL14format_no_copyE:
    .long   512
    .align 4
_ZNSt15regex_constantsL17format_first_onlyE:
    .long   1024
    .align 4
_ZNSt15regex_constantsL13error_collateE:
    .space 4
    .align 4
_ZNSt15regex_constantsL11error_ctypeE:
    .long   1
    .align 4
_ZNSt15regex_constantsL12error_escapeE:
    .long   2
    .align 4
_ZNSt15regex_constantsL13error_backrefE:
    .long   3
    .align 4
_ZNSt15regex_constantsL11error_brackE:
    .long   4
    .align 4
_ZNSt15regex_constantsL11error_parenE:
    .long   5
    .align 4
_ZNSt15regex_constantsL11error_braceE:
    .long   6
    .align 4
_ZNSt15regex_constantsL14error_badbraceE:
    .long   7
    .align 4
_ZNSt15regex_constantsL11error_rangeE:
    .long   8
    .align 4
_ZNSt15regex_constantsL11error_spaceE:
    .long   9
    .align 4
_ZNSt15regex_constantsL15error_badrepeatE:
    .long   10
    .align 4
_ZNSt15regex_constantsL16error_complexityE:
    .long   11
    .align 4
_ZNSt15regex_constantsL11error_stackE:
    .long   12
    .align 4
_ZNSt8__detailL19_S_invalid_state_idE:
    .long   -1
    .text
    .globl  _Z5solvev
    .def    _Z5solvev;  .scl    2;  .type   32; .endef
    .seh_proc   _Z5solvev
_Z5solvev:
.LFB8698:
    pushq   %rbp
    .seh_pushreg    %rbp
    pushq   %rbx
    .seh_pushreg    %rbx
    subq    $136, %rsp
    .seh_stackalloc 136
    leaq    128(%rsp), %rbp
    .seh_setframe   %rbp, 128
    .seh_endprologue
    leaq    -48(%rbp), %rax
    movq    %rax, %rdx
    movq    .refptr._ZSt3cin(%rip), %rcx
.LEHB0:
    call    _ZNSirsERx
.LEHE0:
    leaq    -33(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSaIxEC1Ev
    movq    -48(%rbp), %rax
    movq    %rax, %rcx
    leaq    -33(%rbp), %rdx
    leaq    -80(%rbp), %rax
    movq    %rdx, %r8
    movq    %rcx, %rdx
    movq    %rax, %rcx
.LEHB1:
    call    _ZNSt6vectorIxSaIxEEC1EyRKS0_
.LEHE1:
    leaq    -33(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSaIxED1Ev
    leaq    -80(%rbp), %rax
    movq    %rax, -24(%rbp)
    movq    -24(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt6vectorIxSaIxEE5beginEv
    movq    %rax, -88(%rbp)
    movq    -24(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt6vectorIxSaIxEE3endEv
    movq    %rax, -96(%rbp)
.L3:
    leaq    -96(%rbp), %rdx
    leaq    -88(%rbp), %rax
    movq    %rax, %rcx
    call    _ZN9__gnu_cxxneIPxSt6vectorIxSaIxEEEEbRKNS_17__normal_iteratorIT_T0_EESA_
    testb   %al, %al
    je  .L2
    leaq    -88(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEdeEv
    movq    %rax, -32(%rbp)
    movq    -32(%rbp), %rax
    movq    %rax, %rdx
    movq    .refptr._ZSt3cin(%rip), %rcx
.LEHB2:
    call    _ZNSirsERx
    leaq    -88(%rbp), %rax
    movq    %rax, %rcx
    call    _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEppEv
    jmp .L3
.L2:
    movq    $0, -8(%rbp)
    movq    $1, -16(%rbp)
.L6:
    movq    -48(%rbp), %rax
    cmpq    %rax, -16(%rbp)
    jge .L4
    movq    -16(%rbp), %rax
    subq    $1, %rax
    movq    %rax, %rdx
    leaq    -80(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt6vectorIxSaIxEEixEy
    movq    (%rax), %rbx
    movq    -16(%rbp), %rdx
    leaq    -80(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt6vectorIxSaIxEEixEy
    movq    (%rax), %rax
    cmpq    %rax, %rbx
    setg    %al
    testb   %al, %al
    je  .L5
    addq    $1, -8(%rbp)
    addq    $1, -16(%rbp)
.L5:
    addq    $1, -16(%rbp)
    jmp .L6
.L4:
    movq    -8(%rbp), %rax
    movq    %rax, %rdx
    movq    .refptr._ZSt4cout(%rip), %rcx
    call    _ZNSolsEx
    movl    $10, %edx
    movq    %rax, %rcx
    call    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
.LEHE2:
    leaq    -80(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt6vectorIxSaIxEED1Ev
    jmp .L11
.L9:
    movq    %rax, %rbx
    leaq    -33(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSaIxED1Ev
    movq    %rbx, %rax
    movq    %rax, %rcx
.LEHB3:
    call    _Unwind_Resume
.L10:
    movq    %rax, %rbx
    leaq    -80(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt6vectorIxSaIxEED1Ev
    movq    %rbx, %rax
    movq    %rax, %rcx
    call    _Unwind_Resume
    nop
.LEHE3:
.L11:
    addq    $136, %rsp
    popq    %rbx
    popq    %rbp
    ret
    .def    __gxx_personality_seh0; .scl    2;  .type   32; .endef
    .seh_handler    __gxx_personality_seh0, @unwind, @except
    .seh_handlerdata
.LLSDA8698:
    .byte   0xff
    .byte   0xff
    .byte   0x1
    .uleb128 .LLSDACSE8698-.LLSDACSB8698
.LLSDACSB8698:
    .uleb128 .LEHB0-.LFB8698
    .uleb128 .LEHE0-.LEHB0
    .uleb128 0
    .uleb128 0
    .uleb128 .LEHB1-.LFB8698
    .uleb128 .LEHE1-.LEHB1
    .uleb128 .L9-.LFB8698
    .uleb128 0
    .uleb128 .LEHB2-.LFB8698
    .uleb128 .LEHE2-.LEHB2
    .uleb128 .L10-.LFB8698
    .uleb128 0
    .uleb128 .LEHB3-.LFB8698
    .uleb128 .LEHE3-.LEHB3
    .uleb128 0
    .uleb128 0
.LLSDACSE8698:
    .text
    .seh_endproc
    .def    __main; .scl    2;  .type   32; .endef
    .globl  main
    .def    main;   .scl    2;  .type   32; .endef
    .seh_proc   main
main:
.LFB8699:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $48, %rsp
    .seh_stackalloc 48
    .seh_endprologue
    call    __main
    movl    $0, %edx
    movq    .refptr._ZSt3cin(%rip), %rax
    leaq    16(%rax), %rcx
    call    _ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo
    movl    $0, %ecx
    call    _ZNSt8ios_base15sync_with_stdioEb
    leaq    -8(%rbp), %rax
    movq    %rax, %rdx
    movq    .refptr._ZSt3cin(%rip), %rcx
    call    _ZNSirsERx
.L14:
    movq    -8(%rbp), %rax
    leaq    -1(%rax), %rdx
    movq    %rdx, -8(%rbp)
    testq   %rax, %rax
    setne   %al
    testb   %al, %al
    je  .L13
    call    _Z5solvev
    jmp .L14
.L13:
    movl    $0, %eax
    addq    $48, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSaIxEC1Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSaIxEC1Ev
    .def    _ZNSaIxEC1Ev;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSaIxEC1Ev
_ZNSaIxEC1Ev:
.LFB9262:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rcx
    call    _ZN9__gnu_cxx13new_allocatorIxEC2Ev
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSaIxED2Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSaIxED2Ev
    .def    _ZNSaIxED2Ev;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSaIxED2Ev
_ZNSaIxED2Ev:
.LFB9264:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rcx
    call    _ZN9__gnu_cxx13new_allocatorIxED2Ev
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSaIxED1Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSaIxED1Ev
    .def    _ZNSaIxED1Ev;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSaIxED1Ev
_ZNSaIxED1Ev:
.LFB9265:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rcx
    call    _ZN9__gnu_cxx13new_allocatorIxED2Ev
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt6vectorIxSaIxEEC1EyRKS0_,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt6vectorIxSaIxEEC1EyRKS0_
    .def    _ZNSt6vectorIxSaIxEEC1EyRKS0_;  .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt6vectorIxSaIxEEC1EyRKS0_
_ZNSt6vectorIxSaIxEEC1EyRKS0_:
.LFB9268:
    pushq   %rbp
    .seh_pushreg    %rbp
    pushq   %rbx
    .seh_pushreg    %rbx
    subq    $40, %rsp
    .seh_stackalloc 40
    leaq    128(%rsp), %rbp
    .seh_setframe   %rbp, 128
    .seh_endprologue
    movq    %rcx, -64(%rbp)
    movq    %rdx, -56(%rbp)
    movq    %r8, -48(%rbp)
    movq    -64(%rbp), %rax
    movq    -48(%rbp), %rcx
    movq    -56(%rbp), %rdx
    movq    %rcx, %r8
    movq    %rax, %rcx
.LEHB4:
    call    _ZNSt12_Vector_baseIxSaIxEEC2EyRKS0_
.LEHE4:
    movq    -56(%rbp), %rax
    movq    %rax, %rdx
    movq    -64(%rbp), %rcx
.LEHB5:
    call    _ZNSt6vectorIxSaIxEE21_M_default_initializeEy
.LEHE5:
    jmp .L22
.L21:
    movq    %rax, %rbx
    movq    -64(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt12_Vector_baseIxSaIxEED2Ev
    movq    %rbx, %rax
    movq    %rax, %rcx
.LEHB6:
    call    _Unwind_Resume
    nop
.LEHE6:
.L22:
    addq    $40, %rsp
    popq    %rbx
    popq    %rbp
    ret
    .seh_handler    __gxx_personality_seh0, @unwind, @except
    .seh_handlerdata
.LLSDA9268:
    .byte   0xff
    .byte   0xff
    .byte   0x1
    .uleb128 .LLSDACSE9268-.LLSDACSB9268
.LLSDACSB9268:
    .uleb128 .LEHB4-.LFB9268
    .uleb128 .LEHE4-.LEHB4
    .uleb128 0
    .uleb128 0
    .uleb128 .LEHB5-.LFB9268
    .uleb128 .LEHE5-.LEHB5
    .uleb128 .L21-.LFB9268
    .uleb128 0
    .uleb128 .LEHB6-.LFB9268
    .uleb128 .LEHE6-.LEHB6
    .uleb128 0
    .uleb128 0
.LLSDACSE9268:
    .section    .text$_ZNSt6vectorIxSaIxEEC1EyRKS0_,"x"
    .linkonce discard
    .seh_endproc
    .section    .text$_ZNSt6vectorIxSaIxEED1Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt6vectorIxSaIxEED1Ev
    .def    _ZNSt6vectorIxSaIxEED1Ev;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt6vectorIxSaIxEED1Ev
_ZNSt6vectorIxSaIxEED1Ev:
.LFB9271:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt12_Vector_baseIxSaIxEE19_M_get_Tp_allocatorEv
    movq    %rax, %rcx
    movq    16(%rbp), %rax
    movq    8(%rax), %rdx
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    movq    %rcx, %r8
    movq    %rax, %rcx
    call    _ZSt8_DestroyIPxxEvT_S1_RSaIT0_E
    movq    16(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt12_Vector_baseIxSaIxEED2Ev
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_handler    __gxx_personality_seh0, @unwind, @except
    .seh_handlerdata
.LLSDA9271:
    .byte   0xff
    .byte   0xff
    .byte   0x1
    .uleb128 .LLSDACSE9271-.LLSDACSB9271
.LLSDACSB9271:
.LLSDACSE9271:
    .section    .text$_ZNSt6vectorIxSaIxEED1Ev,"x"
    .linkonce discard
    .seh_endproc
    .section    .text$_ZNSt6vectorIxSaIxEE5beginEv,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt6vectorIxSaIxEE5beginEv
    .def    _ZNSt6vectorIxSaIxEE5beginEv;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt6vectorIxSaIxEE5beginEv
_ZNSt6vectorIxSaIxEE5beginEv:
.LFB9272:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $48, %rsp
    .seh_stackalloc 48
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rdx
    leaq    -8(%rbp), %rax
    movq    %rax, %rcx
    call    _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEC1ERKS1_
    movq    -8(%rbp), %rax
    addq    $48, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt6vectorIxSaIxEE3endEv,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt6vectorIxSaIxEE3endEv
    .def    _ZNSt6vectorIxSaIxEE3endEv; .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt6vectorIxSaIxEE3endEv
_ZNSt6vectorIxSaIxEE3endEv:
.LFB9273:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $48, %rsp
    .seh_stackalloc 48
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    leaq    8(%rax), %rdx
    leaq    -8(%rbp), %rax
    movq    %rax, %rcx
    call    _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEC1ERKS1_
    movq    -8(%rbp), %rax
    addq    $48, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxxneIPxSt6vectorIxSaIxEEEEbRKNS_17__normal_iteratorIT_T0_EESA_,"x"
    .linkonce discard
    .globl  _ZN9__gnu_cxxneIPxSt6vectorIxSaIxEEEEbRKNS_17__normal_iteratorIT_T0_EESA_
    .def    _ZN9__gnu_cxxneIPxSt6vectorIxSaIxEEEEbRKNS_17__normal_iteratorIT_T0_EESA_;  .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxxneIPxSt6vectorIxSaIxEEEEbRKNS_17__normal_iteratorIT_T0_EESA_
_ZN9__gnu_cxxneIPxSt6vectorIxSaIxEEEEbRKNS_17__normal_iteratorIT_T0_EESA_:
.LFB9274:
    pushq   %rbp
    .seh_pushreg    %rbp
    pushq   %rbx
    .seh_pushreg    %rbx
    subq    $40, %rsp
    .seh_stackalloc 40
    leaq    128(%rsp), %rbp
    .seh_setframe   %rbp, 128
    .seh_endprologue
    movq    %rcx, -64(%rbp)
    movq    %rdx, -56(%rbp)
    movq    -64(%rbp), %rcx
    call    _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEE4baseEv
    movq    (%rax), %rbx
    movq    -56(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEE4baseEv
    movq    (%rax), %rax
    cmpq    %rax, %rbx
    setne   %al
    addq    $40, %rsp
    popq    %rbx
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEppEv,"x"
    .linkonce discard
    .align 2
    .globl  _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEppEv
    .def    _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEppEv;  .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEppEv
_ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEppEv:
.LFB9275:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    leaq    8(%rax), %rdx
    movq    16(%rbp), %rax
    movq    %rdx, (%rax)
    movq    16(%rbp), %rax
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEdeEv,"x"
    .linkonce discard
    .align 2
    .globl  _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEdeEv
    .def    _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEdeEv; .scl    2;  .type   32; .endef
    .seh_proc   _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEdeEv
_ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEdeEv:
.LFB9276:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt6vectorIxSaIxEEixEy,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt6vectorIxSaIxEEixEy
    .def    _ZNSt6vectorIxSaIxEEixEy;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt6vectorIxSaIxEEixEy
_ZNSt6vectorIxSaIxEEixEy:
.LFB9277:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    movq    24(%rbp), %rdx
    salq    $3, %rdx
    addq    %rdx, %rax
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxx13new_allocatorIxEC2Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZN9__gnu_cxx13new_allocatorIxEC2Ev
    .def    _ZN9__gnu_cxx13new_allocatorIxEC2Ev;    .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxx13new_allocatorIxEC2Ev
_ZN9__gnu_cxx13new_allocatorIxEC2Ev:
.LFB9578:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    nop
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxx13new_allocatorIxED2Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZN9__gnu_cxx13new_allocatorIxED2Ev
    .def    _ZN9__gnu_cxx13new_allocatorIxED2Ev;    .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxx13new_allocatorIxED2Ev
_ZN9__gnu_cxx13new_allocatorIxED2Ev:
.LFB9581:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    nop
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEE12_Vector_implD1Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEE12_Vector_implD1Ev
    .def    _ZNSt12_Vector_baseIxSaIxEE12_Vector_implD1Ev;  .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEE12_Vector_implD1Ev
_ZNSt12_Vector_baseIxSaIxEE12_Vector_implD1Ev:
.LFB9586:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rcx
    call    _ZNSaIxED2Ev
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEEC2EyRKS0_,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEEC2EyRKS0_
    .def    _ZNSt12_Vector_baseIxSaIxEEC2EyRKS0_;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEEC2EyRKS0_
_ZNSt12_Vector_baseIxSaIxEEC2EyRKS0_:
.LFB9587:
    pushq   %rbp
    .seh_pushreg    %rbp
    pushq   %rbx
    .seh_pushreg    %rbx
    subq    $40, %rsp
    .seh_stackalloc 40
    leaq    128(%rsp), %rbp
    .seh_setframe   %rbp, 128
    .seh_endprologue
    movq    %rcx, -64(%rbp)
    movq    %rdx, -56(%rbp)
    movq    %r8, -48(%rbp)
    movq    -64(%rbp), %rax
    movq    -48(%rbp), %rdx
    movq    %rax, %rcx
    call    _ZNSt12_Vector_baseIxSaIxEE12_Vector_implC1ERKS0_
    movq    -56(%rbp), %rax
    movq    %rax, %rdx
    movq    -64(%rbp), %rcx
.LEHB7:
    call    _ZNSt12_Vector_baseIxSaIxEE17_M_create_storageEy
.LEHE7:
    jmp .L42
.L41:
    movq    %rax, %rbx
    movq    -64(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt12_Vector_baseIxSaIxEE12_Vector_implD1Ev
    movq    %rbx, %rax
    movq    %rax, %rcx
.LEHB8:
    call    _Unwind_Resume
    nop
.LEHE8:
.L42:
    addq    $40, %rsp
    popq    %rbx
    popq    %rbp
    ret
    .seh_handler    __gxx_personality_seh0, @unwind, @except
    .seh_handlerdata
.LLSDA9587:
    .byte   0xff
    .byte   0xff
    .byte   0x1
    .uleb128 .LLSDACSE9587-.LLSDACSB9587
.LLSDACSB9587:
    .uleb128 .LEHB7-.LFB9587
    .uleb128 .LEHE7-.LEHB7
    .uleb128 .L41-.LFB9587
    .uleb128 0
    .uleb128 .LEHB8-.LFB9587
    .uleb128 .LEHE8-.LEHB8
    .uleb128 0
    .uleb128 0
.LLSDACSE9587:
    .section    .text$_ZNSt12_Vector_baseIxSaIxEEC2EyRKS0_,"x"
    .linkonce discard
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEED2Ev,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEED2Ev
    .def    _ZNSt12_Vector_baseIxSaIxEED2Ev;    .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEED2Ev
_ZNSt12_Vector_baseIxSaIxEED2Ev:
.LFB9590:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    movq    16(%rax), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    subq    %rax, %rdx
    movq    %rdx, %rax
    sarq    $3, %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    movq    %rdx, %r8
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZNSt12_Vector_baseIxSaIxEE13_M_deallocateEPxy
    movq    16(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt12_Vector_baseIxSaIxEE12_Vector_implD1Ev
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_handler    __gxx_personality_seh0, @unwind, @except
    .seh_handlerdata
.LLSDA9590:
    .byte   0xff
    .byte   0xff
    .byte   0x1
    .uleb128 .LLSDACSE9590-.LLSDACSB9590
.LLSDACSB9590:
.LLSDACSE9590:
    .section    .text$_ZNSt12_Vector_baseIxSaIxEED2Ev,"x"
    .linkonce discard
    .seh_endproc
    .section    .text$_ZNSt6vectorIxSaIxEE21_M_default_initializeEy,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt6vectorIxSaIxEE21_M_default_initializeEy
    .def    _ZNSt6vectorIxSaIxEE21_M_default_initializeEy;  .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt6vectorIxSaIxEE21_M_default_initializeEy
_ZNSt6vectorIxSaIxEE21_M_default_initializeEy:
.LFB9592:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    16(%rbp), %rax
    movq    %rax, %rcx
    call    _ZNSt12_Vector_baseIxSaIxEE19_M_get_Tp_allocatorEv
    movq    %rax, %rcx
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    movq    24(%rbp), %rdx
    movq    %rcx, %r8
    movq    %rax, %rcx
    call    _ZSt27__uninitialized_default_n_aIPxyxET_S1_T0_RSaIT1_E
    movq    %rax, %rdx
    movq    16(%rbp), %rax
    movq    %rdx, 8(%rax)
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEE19_M_get_Tp_allocatorEv,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEE19_M_get_Tp_allocatorEv
    .def    _ZNSt12_Vector_baseIxSaIxEE19_M_get_Tp_allocatorEv; .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEE19_M_get_Tp_allocatorEv
_ZNSt12_Vector_baseIxSaIxEE19_M_get_Tp_allocatorEv:
.LFB9593:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZSt8_DestroyIPxxEvT_S1_RSaIT0_E,"x"
    .linkonce discard
    .globl  _ZSt8_DestroyIPxxEvT_S1_RSaIT0_E
    .def    _ZSt8_DestroyIPxxEvT_S1_RSaIT0_E;   .scl    2;  .type   32; .endef
    .seh_proc   _ZSt8_DestroyIPxxEvT_S1_RSaIT0_E
_ZSt8_DestroyIPxxEvT_S1_RSaIT0_E:
.LFB9594:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZSt8_DestroyIPxEvT_S1_
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEC1ERKS1_,"x"
    .linkonce discard
    .align 2
    .globl  _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEC1ERKS1_
    .def    _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEC1ERKS1_;  .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEC1ERKS1_
_ZN9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEEC1ERKS1_:
.LFB9597:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    24(%rbp), %rax
    movq    (%rax), %rdx
    movq    16(%rbp), %rax
    movq    %rdx, (%rax)
    nop
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEE4baseEv,"x"
    .linkonce discard
    .align 2
    .globl  _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEE4baseEv
    .def    _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEE4baseEv;  .scl    2;  .type   32; .endef
    .seh_proc   _ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEE4baseEv
_ZNK9__gnu_cxx17__normal_iteratorIPxSt6vectorIxSaIxEEE4baseEv:
.LFB9598:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEE12_Vector_implC1ERKS0_,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEE12_Vector_implC1ERKS0_
    .def    _ZNSt12_Vector_baseIxSaIxEE12_Vector_implC1ERKS0_;  .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEE12_Vector_implC1ERKS0_
_ZNSt12_Vector_baseIxSaIxEE12_Vector_implC1ERKS0_:
.LFB9748:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZNSaIxEC2ERKS_
    movq    16(%rbp), %rax
    movq    $0, (%rax)
    movq    16(%rbp), %rax
    movq    $0, 8(%rax)
    movq    16(%rbp), %rax
    movq    $0, 16(%rax)
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEE17_M_create_storageEy,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEE17_M_create_storageEy
    .def    _ZNSt12_Vector_baseIxSaIxEE17_M_create_storageEy;   .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEE17_M_create_storageEy
_ZNSt12_Vector_baseIxSaIxEE17_M_create_storageEy:
.LFB9749:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZNSt12_Vector_baseIxSaIxEE11_M_allocateEy
    movq    %rax, %rdx
    movq    16(%rbp), %rax
    movq    %rdx, (%rax)
    movq    16(%rbp), %rax
    movq    (%rax), %rdx
    movq    16(%rbp), %rax
    movq    %rdx, 8(%rax)
    movq    16(%rbp), %rax
    movq    (%rax), %rax
    movq    24(%rbp), %rdx
    salq    $3, %rdx
    addq    %rax, %rdx
    movq    16(%rbp), %rax
    movq    %rdx, 16(%rax)
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEE13_M_deallocateEPxy,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEE13_M_deallocateEPxy
    .def    _ZNSt12_Vector_baseIxSaIxEE13_M_deallocateEPxy; .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEE13_M_deallocateEPxy
_ZNSt12_Vector_baseIxSaIxEE13_M_deallocateEPxy:
.LFB9750:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    cmpq    $0, 24(%rbp)
    je  .L55
    movq    16(%rbp), %rax
    movq    32(%rbp), %rcx
    movq    24(%rbp), %rdx
    movq    %rcx, %r8
    movq    %rax, %rcx
    call    _ZNSt16allocator_traitsISaIxEE10deallocateERS0_Pxy
.L55:
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZSt27__uninitialized_default_n_aIPxyxET_S1_T0_RSaIT1_E,"x"
    .linkonce discard
    .globl  _ZSt27__uninitialized_default_n_aIPxyxET_S1_T0_RSaIT1_E
    .def    _ZSt27__uninitialized_default_n_aIPxyxET_S1_T0_RSaIT1_E;    .scl    2;  .type   32; .endef
    .seh_proc   _ZSt27__uninitialized_default_n_aIPxyxET_S1_T0_RSaIT1_E
_ZSt27__uninitialized_default_n_aIPxyxET_S1_T0_RSaIT1_E:
.LFB9751:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZSt25__uninitialized_default_nIPxyET_S1_T0_
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZSt8_DestroyIPxEvT_S1_,"x"
    .linkonce discard
    .globl  _ZSt8_DestroyIPxEvT_S1_
    .def    _ZSt8_DestroyIPxEvT_S1_;    .scl    2;  .type   32; .endef
    .seh_proc   _ZSt8_DestroyIPxEvT_S1_
_ZSt8_DestroyIPxEvT_S1_:
.LFB9752:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZNSt12_Destroy_auxILb1EE9__destroyIPxEEvT_S3_
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSaIxEC2ERKS_,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSaIxEC2ERKS_
    .def    _ZNSaIxEC2ERKS_;    .scl    2;  .type   32; .endef
    .seh_proc   _ZNSaIxEC2ERKS_
_ZNSaIxEC2ERKS_:
.LFB9856:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZN9__gnu_cxx13new_allocatorIxEC2ERKS1_
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Vector_baseIxSaIxEE11_M_allocateEy,"x"
    .linkonce discard
    .align 2
    .globl  _ZNSt12_Vector_baseIxSaIxEE11_M_allocateEy
    .def    _ZNSt12_Vector_baseIxSaIxEE11_M_allocateEy; .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Vector_baseIxSaIxEE11_M_allocateEy
_ZNSt12_Vector_baseIxSaIxEE11_M_allocateEy:
.LFB9858:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    cmpq    $0, 24(%rbp)
    je  .L61
    movq    16(%rbp), %rax
    movq    24(%rbp), %rdx
    movq    %rax, %rcx
    call    _ZNSt16allocator_traitsISaIxEE8allocateERS0_y
    jmp .L63
.L61:
    movl    $0, %eax
.L63:
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt16allocator_traitsISaIxEE10deallocateERS0_Pxy,"x"
    .linkonce discard
    .globl  _ZNSt16allocator_traitsISaIxEE10deallocateERS0_Pxy
    .def    _ZNSt16allocator_traitsISaIxEE10deallocateERS0_Pxy; .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt16allocator_traitsISaIxEE10deallocateERS0_Pxy
_ZNSt16allocator_traitsISaIxEE10deallocateERS0_Pxy:
.LFB9859:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    movq    32(%rbp), %rdx
    movq    24(%rbp), %rax
    movq    %rdx, %r8
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZN9__gnu_cxx13new_allocatorIxE10deallocateEPxy
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZSt25__uninitialized_default_nIPxyET_S1_T0_,"x"
    .linkonce discard
    .globl  _ZSt25__uninitialized_default_nIPxyET_S1_T0_
    .def    _ZSt25__uninitialized_default_nIPxyET_S1_T0_;   .scl    2;  .type   32; .endef
    .seh_proc   _ZSt25__uninitialized_default_nIPxyET_S1_T0_
_ZSt25__uninitialized_default_nIPxyET_S1_T0_:
.LFB9860:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $48, %rsp
    .seh_stackalloc 48
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movb    $1, -1(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZNSt27__uninitialized_default_n_1ILb1EE18__uninit_default_nIPxyEET_S3_T0_
    addq    $48, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt12_Destroy_auxILb1EE9__destroyIPxEEvT_S3_,"x"
    .linkonce discard
    .globl  _ZNSt12_Destroy_auxILb1EE9__destroyIPxEEvT_S3_
    .def    _ZNSt12_Destroy_auxILb1EE9__destroyIPxEEvT_S3_; .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt12_Destroy_auxILb1EE9__destroyIPxEEvT_S3_
_ZNSt12_Destroy_auxILb1EE9__destroyIPxEEvT_S3_:
.LFB9861:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    nop
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxx13new_allocatorIxEC2ERKS1_,"x"
    .linkonce discard
    .align 2
    .globl  _ZN9__gnu_cxx13new_allocatorIxEC2ERKS1_
    .def    _ZN9__gnu_cxx13new_allocatorIxEC2ERKS1_;    .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxx13new_allocatorIxEC2ERKS1_
_ZN9__gnu_cxx13new_allocatorIxEC2ERKS1_:
.LFB9934:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    nop
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt16allocator_traitsISaIxEE8allocateERS0_y,"x"
    .linkonce discard
    .globl  _ZNSt16allocator_traitsISaIxEE8allocateERS0_y
    .def    _ZNSt16allocator_traitsISaIxEE8allocateERS0_y;  .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt16allocator_traitsISaIxEE8allocateERS0_y
_ZNSt16allocator_traitsISaIxEE8allocateERS0_y:
.LFB9936:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    24(%rbp), %rax
    movl    $0, %r8d
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZN9__gnu_cxx13new_allocatorIxE8allocateEyPKv
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxx13new_allocatorIxE10deallocateEPxy,"x"
    .linkonce discard
    .align 2
    .globl  _ZN9__gnu_cxx13new_allocatorIxE10deallocateEPxy
    .def    _ZN9__gnu_cxx13new_allocatorIxE10deallocateEPxy;    .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxx13new_allocatorIxE10deallocateEPxy
_ZN9__gnu_cxx13new_allocatorIxE10deallocateEPxy:
.LFB9937:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, %rcx
    call    _ZdlPv
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNSt27__uninitialized_default_n_1ILb1EE18__uninit_default_nIPxyEET_S3_T0_,"x"
    .linkonce discard
    .globl  _ZNSt27__uninitialized_default_n_1ILb1EE18__uninit_default_nIPxyEET_S3_T0_
    .def    _ZNSt27__uninitialized_default_n_1ILb1EE18__uninit_default_nIPxyEET_S3_T0_; .scl    2;  .type   32; .endef
    .seh_proc   _ZNSt27__uninitialized_default_n_1ILb1EE18__uninit_default_nIPxyEET_S3_T0_
_ZNSt27__uninitialized_default_n_1ILb1EE18__uninit_default_nIPxyEET_S3_T0_:
.LFB9938:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $48, %rsp
    .seh_stackalloc 48
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    $0, -8(%rbp)
    leaq    -8(%rbp), %rdx
    movq    24(%rbp), %rax
    movq    %rdx, %r8
    movq    %rax, %rdx
    movq    16(%rbp), %rcx
    call    _ZSt6fill_nIPxyxET_S1_T0_RKT1_
    addq    $48, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZN9__gnu_cxx13new_allocatorIxE8allocateEyPKv,"x"
    .linkonce discard
    .align 2
    .globl  _ZN9__gnu_cxx13new_allocatorIxE8allocateEyPKv
    .def    _ZN9__gnu_cxx13new_allocatorIxE8allocateEyPKv;  .scl    2;  .type   32; .endef
    .seh_proc   _ZN9__gnu_cxx13new_allocatorIxE8allocateEyPKv
_ZN9__gnu_cxx13new_allocatorIxE8allocateEyPKv:
.LFB10030:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    movq    16(%rbp), %rcx
    call    _ZNK9__gnu_cxx13new_allocatorIxE8max_sizeEv
    cmpq    %rax, 24(%rbp)
    seta    %al
    testb   %al, %al
    je  .L75
    call    _ZSt17__throw_bad_allocv
.L75:
    movq    24(%rbp), %rax
    salq    $3, %rax
    movq    %rax, %rcx
    call    _Znwy
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZSt6fill_nIPxyxET_S1_T0_RKT1_,"x"
    .linkonce discard
    .globl  _ZSt6fill_nIPxyxET_S1_T0_RKT1_
    .def    _ZSt6fill_nIPxyxET_S1_T0_RKT1_; .scl    2;  .type   32; .endef
    .seh_proc   _ZSt6fill_nIPxyxET_S1_T0_RKT1_
_ZSt6fill_nIPxyxET_S1_T0_RKT1_:
.LFB10031:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    movq    16(%rbp), %rcx
    call    _ZSt12__niter_baseIPxET_S1_
    movq    %rax, %rcx
    movq    32(%rbp), %rdx
    movq    24(%rbp), %rax
    movq    %rdx, %r8
    movq    %rax, %rdx
    call    _ZSt10__fill_n_aIPxyxEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT1_E7__valueET_E6__typeES6_T0_RKS4_
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZNK9__gnu_cxx13new_allocatorIxE8max_sizeEv,"x"
    .linkonce discard
    .align 2
    .globl  _ZNK9__gnu_cxx13new_allocatorIxE8max_sizeEv
    .def    _ZNK9__gnu_cxx13new_allocatorIxE8max_sizeEv;    .scl    2;  .type   32; .endef
    .seh_proc   _ZNK9__gnu_cxx13new_allocatorIxE8max_sizeEv
_ZNK9__gnu_cxx13new_allocatorIxE8max_sizeEv:
.LFB10089:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movabsq $2305843009213693951, %rax
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZSt12__niter_baseIPxET_S1_,"x"
    .linkonce discard
    .globl  _ZSt12__niter_baseIPxET_S1_
    .def    _ZSt12__niter_baseIPxET_S1_;    .scl    2;  .type   32; .endef
    .seh_proc   _ZSt12__niter_baseIPxET_S1_
_ZSt12__niter_baseIPxET_S1_:
.LFB10090:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    16(%rbp), %rax
    popq    %rbp
    ret
    .seh_endproc
    .section    .text$_ZSt10__fill_n_aIPxyxEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT1_E7__valueET_E6__typeES6_T0_RKS4_,"x"
    .linkonce discard
    .globl  _ZSt10__fill_n_aIPxyxEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT1_E7__valueET_E6__typeES6_T0_RKS4_
    .def    _ZSt10__fill_n_aIPxyxEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT1_E7__valueET_E6__typeES6_T0_RKS4_;  .scl    2;  .type   32; .endef
    .seh_proc   _ZSt10__fill_n_aIPxyxEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT1_E7__valueET_E6__typeES6_T0_RKS4_
_ZSt10__fill_n_aIPxyxEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT1_E7__valueET_E6__typeES6_T0_RKS4_:
.LFB10091:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $16, %rsp
    .seh_stackalloc 16
    .seh_endprologue
    movq    %rcx, 16(%rbp)
    movq    %rdx, 24(%rbp)
    movq    %r8, 32(%rbp)
    movq    32(%rbp), %rax
    movq    (%rax), %rax
    movq    %rax, -16(%rbp)
    movq    24(%rbp), %rax
    movq    %rax, -8(%rbp)
.L85:
    cmpq    $0, -8(%rbp)
    je  .L84
    movq    16(%rbp), %rax
    movq    -16(%rbp), %rdx
    movq    %rdx, (%rax)
    subq    $1, -8(%rbp)
    addq    $8, 16(%rbp)
    jmp .L85
.L84:
    movq    16(%rbp), %rax
    addq    $16, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .text
    .def    __tcf_0;    .scl    3;  .type   32; .endef
    .seh_proc   __tcf_0
__tcf_0:
.LFB10140:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    leaq    _ZStL8__ioinit(%rip), %rcx
    call    _ZNSt8ios_base4InitD1Ev
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .def    _Z41__static_initialization_and_destruction_0ii;    .scl    3;  .type   32; .endef
    .seh_proc   _Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB10139:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movl    %ecx, 16(%rbp)
    movl    %edx, 24(%rbp)
    cmpl    $1, 16(%rbp)
    jne .L90
    cmpl    $65535, 24(%rbp)
    jne .L90
    leaq    _ZStL8__ioinit(%rip), %rcx
    call    _ZNSt8ios_base4InitC1Ev
    leaq    __tcf_0(%rip), %rcx
    call    atexit
.L90:
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .def    _GLOBAL__sub_I__Z5solvev;   .scl    3;  .type   32; .endef
    .seh_proc   _GLOBAL__sub_I__Z5solvev
_GLOBAL__sub_I__Z5solvev:
.LFB10163:
    pushq   %rbp
    .seh_pushreg    %rbp
    movq    %rsp, %rbp
    .seh_setframe   %rbp, 0
    subq    $32, %rsp
    .seh_stackalloc 32
    .seh_endprologue
    movl    $65535, %edx
    movl    $1, %ecx
    call    _Z41__static_initialization_and_destruction_0ii
    nop
    addq    $32, %rsp
    popq    %rbp
    ret
    .seh_endproc
    .section    .ctors,"w"
    .align 8
    .quad   _GLOBAL__sub_I__Z5solvev
    .ident  "GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 7.3.0"
    .def    _ZNSirsERx; .scl    2;  .type   32; .endef
    .def    _ZNSolsEx;  .scl    2;  .type   32; .endef
    .def    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;  .scl    2;  .type   32; .endef
    .def    _Unwind_Resume; .scl    2;  .type   32; .endef
    .def    _ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo;   .scl    2;  .type   32; .endef
    .def    _ZNSt8ios_base15sync_with_stdioEb;  .scl    2;  .type   32; .endef
    .def    _ZdlPv; .scl    2;  .type   32; .endef
    .def    _ZSt17__throw_bad_allocv;   .scl    2;  .type   32; .endef
    .def    _Znwy;  .scl    2;  .type   32; .endef
    .def    _ZNSt8ios_base4InitD1Ev;    .scl    2;  .type   32; .endef
    .def    _ZNSt8ios_base4InitC1Ev;    .scl    2;  .type   32; .endef
    .def    atexit; .scl    2;  .type   32; .endef
    .section    .rdata$.refptr._ZSt4cout, "dr"
    .globl  .refptr._ZSt4cout
    .linkonce   discard
.refptr._ZSt4cout:
    .quad   _ZSt4cout
    .section    .rdata$.refptr._ZSt3cin, "dr"
    .globl  .refptr._ZSt3cin
    .linkonce   discard
.refptr._ZSt3cin:
    .quad   _ZSt3cin
)");