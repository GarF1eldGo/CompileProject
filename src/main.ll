; ModuleID = 'module'
source_filename = "module"

@_Const_String_ = private constant [6 x i8] c"%d %d\00"
@_Const_String_.1 = private constant [3 x i8] c"%d\00"
@_Const_String_.2 = private constant [6 x i8] c"%d %d\00"
@_Const_String_.3 = private constant [3 x i8] c"%d\00"
@_Const_String_.4 = private constant [25 x i8] c"Incompatible Dimensions\0A\00"
@_Const_String_.5 = private constant [4 x i8] c"%d\0A\00"

declare i32 @printf(i8* %0, ...)

declare i32 @scanf(i8* %0, ...)

define i32 @main() {
main:
  %A = alloca [25 x [25 x i32]], align 4
  %B = alloca [25 x [25 x i32]], align 4
  %C = alloca [25 x [25 x i32]], align 4
  %Ma = alloca i32, align 4
  %Na = alloca i32, align 4
  %Mb = alloca i32, align 4
  %Nb = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %tmpvar = load i32, i32* %Ma, align 4
  %tmpvar1 = load i32, i32* %Na, align 4
  %scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_Const_String_, i32 0, i32 0), i32* %Ma, i32* %Na)
  %tmpvar2 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar3 = load i32, i32* %i, align 4
  %tmpvar4 = load i32, i32* %Ma, align 4
  %tmpcmp = icmp slt i32 %tmpvar3, %tmpvar4
  br i1 %tmpcmp, label %forloop, label %forcont

forloop:                                          ; preds = %forcont7, %main
  %tmpvar5 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar8 = load i32, i32* %j, align 4
  %tmpvar9 = load i32, i32* %Na, align 4
  %tmpcmp10 = icmp slt i32 %tmpvar8, %tmpvar9
  br i1 %tmpcmp10, label %forloop6, label %forcont7

forcont:                                          ; preds = %forcont7, %main
  %tmpvar25 = load i32, i32* %Mb, align 4
  %tmpvar26 = load i32, i32* %Nb, align 4
  %scanf27 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_Const_String_.2, i32 0, i32 0), i32* %Mb, i32* %Nb)
  %tmpvar28 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar31 = load i32, i32* %i, align 4
  %tmpvar32 = load i32, i32* %Mb, align 4
  %tmpcmp33 = icmp slt i32 %tmpvar31, %tmpvar32
  br i1 %tmpcmp33, label %forloop29, label %forcont30

forloop6:                                         ; preds = %forloop6, %forloop
  %tmpvar11 = load i32, i32* %i, align 4
  %tmpvar12 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %A, i32 %tmpvar11, i32 %tmpvar11
  %tmpvar13 = load i32, i32* %j, align 4
  %tmpvar14 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar12, i32 %tmpvar13, i32 %tmpvar13
  %scanf15 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.1, i32 0, i32 0), i32* %tmpvar14)
  %tmpvar16 = load i32, i32* %j, align 4
  %tmpAdd = add i32 %tmpvar16, 1
  store volatile i32 %tmpAdd, i32* %j, align 4
  %tmpvar17 = load i32, i32* %j, align 4
  %tmpvar18 = load i32, i32* %Na, align 4
  %tmpcmp19 = icmp slt i32 %tmpvar17, %tmpvar18
  br i1 %tmpcmp19, label %forloop6, label %forcont7

forcont7:                                         ; preds = %forloop6, %forloop
  %tmpvar20 = load i32, i32* %i, align 4
  %tmpAdd21 = add i32 %tmpvar20, 1
  store volatile i32 %tmpAdd21, i32* %i, align 4
  %tmpvar22 = load i32, i32* %i, align 4
  %tmpvar23 = load i32, i32* %Ma, align 4
  %tmpcmp24 = icmp slt i32 %tmpvar22, %tmpvar23
  br i1 %tmpcmp24, label %forloop, label %forcont

forloop29:                                        ; preds = %forcont36, %forcont
  %tmpvar34 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar37 = load i32, i32* %j, align 4
  %tmpvar38 = load i32, i32* %Nb, align 4
  %tmpcmp39 = icmp slt i32 %tmpvar37, %tmpvar38
  br i1 %tmpcmp39, label %forloop35, label %forcont36

forcont30:                                        ; preds = %forcont36, %forcont
  %tmpvar56 = load i32, i32* %Na, align 4
  %tmpvar57 = load i32, i32* %Mb, align 4
  %tmpcmp58 = icmp ne i32 %tmpvar56, %tmpvar57
  br i1 %tmpcmp58, label %then, label %else

forloop35:                                        ; preds = %forloop35, %forloop29
  %tmpvar40 = load i32, i32* %i, align 4
  %tmpvar41 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %B, i32 %tmpvar40, i32 %tmpvar40
  %tmpvar42 = load i32, i32* %j, align 4
  %tmpvar43 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar41, i32 %tmpvar42, i32 %tmpvar42
  %tmpvar44 = load i32, i32* %tmpvar43, align 4
  %scanf45 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.3, i32 0, i32 0), i32* %tmpvar43)
  %tmpvar46 = load i32, i32* %j, align 4
  %tmpAdd47 = add i32 %tmpvar46, 1
  store volatile i32 %tmpAdd47, i32* %j, align 4
  %tmpvar48 = load i32, i32* %j, align 4
  %tmpvar49 = load i32, i32* %Nb, align 4
  %tmpcmp50 = icmp slt i32 %tmpvar48, %tmpvar49
  br i1 %tmpcmp50, label %forloop35, label %forcont36

forcont36:                                        ; preds = %forloop35, %forloop29
  %tmpvar51 = load i32, i32* %i, align 4
  %tmpAdd52 = add i32 %tmpvar51, 1
  store volatile i32 %tmpAdd52, i32* %i, align 4
  %tmpvar53 = load i32, i32* %i, align 4
  %tmpvar54 = load i32, i32* %Mb, align 4
  %tmpcmp55 = icmp slt i32 %tmpvar53, %tmpvar54
  br i1 %tmpcmp55, label %forloop29, label %forcont30

then:                                             ; preds = %forcont30
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @_Const_String_.4, i32 0, i32 0))
  ret i32 0
  br label %merge

else:                                             ; preds = %forcont30
  br label %merge

merge:                                            ; preds = %else, %then
  %tmpvar59 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar62 = load i32, i32* %i, align 4
  %tmpvar63 = load i32, i32* %Ma, align 4
  %tmpcmp64 = icmp slt i32 %tmpvar62, %tmpvar63
  br i1 %tmpcmp64, label %forloop60, label %forcont61

forloop60:                                        ; preds = %forcont67, %merge
  %tmpvar65 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar68 = load i32, i32* %j, align 4
  %tmpvar69 = load i32, i32* %Nb, align 4
  %tmpcmp70 = icmp slt i32 %tmpvar68, %tmpvar69
  br i1 %tmpcmp70, label %forloop66, label %forcont67

forcont61:                                        ; preds = %forcont67, %merge
  %tmpvar112 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar115 = load i32, i32* %i, align 4
  %tmpvar116 = load i32, i32* %Ma, align 4
  %tmpcmp117 = icmp slt i32 %tmpvar115, %tmpvar116
  br i1 %tmpcmp117, label %forloop113, label %forcont114

forloop66:                                        ; preds = %forcont78, %forloop60
  %tmpvar71 = load i32, i32* %i, align 4
  %tmpvar72 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %C, i32 %tmpvar71, i32 %tmpvar71
  %tmpvar73 = load i32, i32* %j, align 4
  %tmpvar74 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar72, i32 %tmpvar73, i32 %tmpvar73
  %tmpvar75 = load i32, i32* %tmpvar74, align 4
  store i32 0, i32* %tmpvar74, align 4
  %tmpvar76 = load i32, i32* %k, align 4
  store i32 0, i32* %k, align 4
  %tmpvar79 = load i32, i32* %k, align 4
  %tmpvar80 = load i32, i32* %Na, align 4
  %tmpcmp81 = icmp slt i32 %tmpvar79, %tmpvar80
  br i1 %tmpcmp81, label %forloop77, label %forcont78

forcont67:                                        ; preds = %forcont78, %forloop60
  %tmpvar107 = load i32, i32* %i, align 4
  %tmpAdd108 = add i32 %tmpvar107, 1
  store volatile i32 %tmpAdd108, i32* %i, align 4
  %tmpvar109 = load i32, i32* %i, align 4
  %tmpvar110 = load i32, i32* %Ma, align 4
  %tmpcmp111 = icmp slt i32 %tmpvar109, %tmpvar110
  br i1 %tmpcmp111, label %forloop60, label %forcont61

forloop77:                                        ; preds = %forloop77, %forloop66
  %tmpvar82 = load i32, i32* %i, align 4
  %tmpvar83 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %C, i32 %tmpvar82, i32 %tmpvar82
  %tmpvar84 = load i32, i32* %j, align 4
  %tmpvar85 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar83, i32 %tmpvar84, i32 %tmpvar84
  %tmpvar86 = load i32, i32* %i, align 4
  %tmpvar87 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %A, i32 %tmpvar86, i32 %tmpvar86
  %tmpvar88 = load i32, i32* %k, align 4
  %tmpvar89 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar87, i32 %tmpvar88, i32 %tmpvar88
  %tmpvar90 = load i32, i32* %k, align 4
  %tmpvar91 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %B, i32 %tmpvar90, i32 %tmpvar90
  %tmpvar92 = load i32, i32* %j, align 4
  %tmpvar93 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar91, i32 %tmpvar92, i32 %tmpvar92
  %tmpvar94 = load i32, i32* %tmpvar89, align 4
  %tmpvar95 = load i32, i32* %tmpvar93, align 4
  %tmpmul = mul i32 %tmpvar94, %tmpvar95
  %tmpvar96 = load i32, i32* %tmpvar85, align 4
  %tmpadd = add i32 %tmpvar96, %tmpmul
  store i32 %tmpadd, i32* %tmpvar85, align 4
  %tmpvar97 = load i32, i32* %k, align 4
  %tmpAdd98 = add i32 %tmpvar97, 1
  store volatile i32 %tmpAdd98, i32* %k, align 4
  %tmpvar99 = load i32, i32* %k, align 4
  %tmpvar100 = load i32, i32* %Na, align 4
  %tmpcmp101 = icmp slt i32 %tmpvar99, %tmpvar100
  br i1 %tmpcmp101, label %forloop77, label %forcont78

forcont78:                                        ; preds = %forloop77, %forloop66
  %tmpvar102 = load i32, i32* %j, align 4
  %tmpAdd103 = add i32 %tmpvar102, 1
  store volatile i32 %tmpAdd103, i32* %j, align 4
  %tmpvar104 = load i32, i32* %j, align 4
  %tmpvar105 = load i32, i32* %Nb, align 4
  %tmpcmp106 = icmp slt i32 %tmpvar104, %tmpvar105
  br i1 %tmpcmp106, label %forloop66, label %forcont67

forloop113:                                       ; preds = %forcont120, %forcont61
  %tmpvar118 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar121 = load i32, i32* %j, align 4
  %tmpvar122 = load i32, i32* %Nb, align 4
  %tmpcmp123 = icmp slt i32 %tmpvar121, %tmpvar122
  br i1 %tmpcmp123, label %forloop119, label %forcont120

forcont114:                                       ; preds = %forcont120, %forcont61
  %tmpvar140 = load i32, i32* %i, align 4
  store i32 1, i32* %i, align 4
  ret i32 0

forloop119:                                       ; preds = %forloop119, %forloop113
  %tmpvar124 = load i32, i32* %i, align 4
  %tmpvar125 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %C, i32 %tmpvar124, i32 %tmpvar124
  %tmpvar126 = load i32, i32* %j, align 4
  %tmpvar127 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar125, i32 %tmpvar126, i32 %tmpvar126
  %tmpvar128 = load i32, i32* %tmpvar127, align 4
  %printf129 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.5, i32 0, i32 0), i32 %tmpvar128)
  %tmpvar130 = load i32, i32* %j, align 4
  %tmpAdd131 = add i32 %tmpvar130, 1
  store volatile i32 %tmpAdd131, i32* %j, align 4
  %tmpvar132 = load i32, i32* %j, align 4
  %tmpvar133 = load i32, i32* %Nb, align 4
  %tmpcmp134 = icmp slt i32 %tmpvar132, %tmpvar133
  br i1 %tmpcmp134, label %forloop119, label %forcont120

forcont120:                                       ; preds = %forloop119, %forloop113
  %tmpvar135 = load i32, i32* %i, align 4
  %tmpAdd136 = add i32 %tmpvar135, 1
  store volatile i32 %tmpAdd136, i32* %i, align 4
  %tmpvar137 = load i32, i32* %i, align 4
  %tmpvar138 = load i32, i32* %Ma, align 4
  %tmpcmp139 = icmp slt i32 %tmpvar137, %tmpvar138
  br i1 %tmpcmp139, label %forloop113, label %forcont114
}
