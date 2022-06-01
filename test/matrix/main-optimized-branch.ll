; ModuleID = 'matrix/main-optimized-branch.bc'
source_filename = "module"

@_Const_String_ = private constant [6 x i8] c"%d %d\00"
@_Const_String_.1 = private constant [4 x i8] c"%6d\00"
@_Const_String_.2 = private constant [6 x i8] c"%d %d\00"
@_Const_String_.3 = private constant [4 x i8] c"%6d\00"
@_Const_String_.4 = private constant [25 x i8] c"Incompatible Dimensions\0A\00"
@_Const_String_.5 = private constant [5 x i8] c"%10d\00"
@_Const_String_.6 = private constant [2 x i8] c"\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
main:
  %A = alloca [25 x [25 x i32]], align 4
  %B = alloca [25 x [25 x i32]], align 4
  %C = alloca [25 x [25 x i32]], align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %j, align 4
  %k = alloca i32, align 4
  store i32 0, i32* %k, align 4
  %Ma = alloca i32, align 4
  store i32 0, i32* %Ma, align 4
  %Na = alloca i32, align 4
  store i32 0, i32* %Na, align 4
  %Mb = alloca i32, align 4
  store i32 0, i32* %Mb, align 4
  %Nb = alloca i32, align 4
  store i32 0, i32* %Nb, align 4
  %scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_Const_String_, i32 0, i32 0), i32* %Ma, i32* %Na)
  %tmpvar = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar1 = load i32, i32* %i, align 4
  %tmpvar2 = load i32, i32* %Ma, align 4
  %tmpcmp = icmp slt i32 %tmpvar1, %tmpvar2
  br i1 %tmpcmp, label %forloop, label %forcont

forloop:                                          ; preds = %foradd, %main
  %tmpvar3 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar7 = load i32, i32* %j, align 4
  %tmpvar8 = load i32, i32* %Na, align 4
  %tmpcmp9 = icmp slt i32 %tmpvar7, %tmpvar8
  br i1 %tmpcmp9, label %forloop6, label %forcont4

foradd:                                           ; preds = %forcont4
  %tmpvar19 = load i32, i32* %i, align 4
  %tmpAdd20 = add i32 %tmpvar19, 1
  store volatile i32 %tmpAdd20, i32* %i, align 4
  %tmpvar21 = load i32, i32* %i, align 4
  %tmpvar22 = load i32, i32* %Ma, align 4
  %tmpcmp23 = icmp slt i32 %tmpvar21, %tmpvar22
  br i1 %tmpcmp23, label %forloop, label %forcont

forcont:                                          ; preds = %foradd, %main
  %scanf24 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_Const_String_.2, i32 0, i32 0), i32* %Mb, i32* %Nb)
  %tmpvar25 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar29 = load i32, i32* %i, align 4
  %tmpvar30 = load i32, i32* %Mb, align 4
  %tmpcmp31 = icmp slt i32 %tmpvar29, %tmpvar30
  br i1 %tmpcmp31, label %forloop28, label %forcont26

forloop6:                                         ; preds = %foradd5, %forloop
  %tmpvar10 = load i32, i32* %i, align 4
  %tmpvar11 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %A, i32 0, i32 %tmpvar10
  %tmpvar12 = load i32, i32* %j, align 4
  %tmpvar13 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar11, i32 0, i32 %tmpvar12
  %scanf14 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.1, i32 0, i32 0), i32* %tmpvar13)
  br label %foradd5

foradd5:                                          ; preds = %forloop6
  %tmpvar15 = load i32, i32* %j, align 4
  %tmpAdd = add i32 %tmpvar15, 1
  store volatile i32 %tmpAdd, i32* %j, align 4
  %tmpvar16 = load i32, i32* %j, align 4
  %tmpvar17 = load i32, i32* %Na, align 4
  %tmpcmp18 = icmp slt i32 %tmpvar16, %tmpvar17
  br i1 %tmpcmp18, label %forloop6, label %forcont4

forcont4:                                         ; preds = %foradd5, %forloop
  br label %foradd

forloop28:                                        ; preds = %foradd27, %forcont
  %tmpvar32 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar36 = load i32, i32* %j, align 4
  %tmpvar37 = load i32, i32* %Nb, align 4
  %tmpcmp38 = icmp slt i32 %tmpvar36, %tmpvar37
  br i1 %tmpcmp38, label %forloop35, label %forcont33

foradd27:                                         ; preds = %forcont33
  %tmpvar49 = load i32, i32* %i, align 4
  %tmpAdd50 = add i32 %tmpvar49, 1
  store volatile i32 %tmpAdd50, i32* %i, align 4
  %tmpvar51 = load i32, i32* %i, align 4
  %tmpvar52 = load i32, i32* %Mb, align 4
  %tmpcmp53 = icmp slt i32 %tmpvar51, %tmpvar52
  br i1 %tmpcmp53, label %forloop28, label %forcont26

forcont26:                                        ; preds = %foradd27, %forcont
  %tmpvar54 = load i32, i32* %Na, align 4
  %tmpvar55 = load i32, i32* %Mb, align 4
  %tmpcmp56 = icmp ne i32 %tmpvar54, %tmpvar55
  br i1 %tmpcmp56, label %then, label %else

forloop35:                                        ; preds = %foradd34, %forloop28
  %tmpvar39 = load i32, i32* %i, align 4
  %tmpvar40 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %B, i32 0, i32 %tmpvar39
  %tmpvar41 = load i32, i32* %j, align 4
  %tmpvar42 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar40, i32 0, i32 %tmpvar41
  %scanf43 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.3, i32 0, i32 0), i32* %tmpvar42)
  br label %foradd34

foradd34:                                         ; preds = %forloop35
  %tmpvar44 = load i32, i32* %j, align 4
  %tmpAdd45 = add i32 %tmpvar44, 1
  store volatile i32 %tmpAdd45, i32* %j, align 4
  %tmpvar46 = load i32, i32* %j, align 4
  %tmpvar47 = load i32, i32* %Nb, align 4
  %tmpcmp48 = icmp slt i32 %tmpvar46, %tmpvar47
  br i1 %tmpcmp48, label %forloop35, label %forcont33

forcont33:                                        ; preds = %foradd34, %forloop28
  br label %foradd27

then:                                             ; preds = %forcont26
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @_Const_String_.4, i32 0, i32 0))
  ret i32 0

else:                                             ; preds = %forcont26
  br label %merge

merge:                                            ; preds = %else
  %tmpvar57 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar61 = load i32, i32* %i, align 4
  %tmpvar62 = load i32, i32* %Ma, align 4
  %tmpcmp63 = icmp slt i32 %tmpvar61, %tmpvar62
  br i1 %tmpcmp63, label %forloop60, label %forcont58

forloop60:                                        ; preds = %foradd59, %merge
  %tmpvar64 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar68 = load i32, i32* %j, align 4
  %tmpvar69 = load i32, i32* %Nb, align 4
  %tmpcmp70 = icmp slt i32 %tmpvar68, %tmpvar69
  br i1 %tmpcmp70, label %forloop67, label %forcont65

foradd59:                                         ; preds = %forcont65
  %tmpvar108 = load i32, i32* %i, align 4
  %tmpAdd109 = add i32 %tmpvar108, 1
  store volatile i32 %tmpAdd109, i32* %i, align 4
  %tmpvar110 = load i32, i32* %i, align 4
  %tmpvar111 = load i32, i32* %Ma, align 4
  %tmpcmp112 = icmp slt i32 %tmpvar110, %tmpvar111
  br i1 %tmpcmp112, label %forloop60, label %forcont58

forcont58:                                        ; preds = %foradd59, %merge
  %tmpvar113 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar117 = load i32, i32* %i, align 4
  %tmpvar118 = load i32, i32* %Ma, align 4
  %tmpcmp119 = icmp slt i32 %tmpvar117, %tmpvar118
  br i1 %tmpcmp119, label %forloop116, label %forcont114

forloop67:                                        ; preds = %foradd66, %forloop60
  %tmpvar71 = load i32, i32* %i, align 4
  %tmpvar72 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %C, i32 0, i32 %tmpvar71
  %tmpvar73 = load i32, i32* %j, align 4
  %tmpvar74 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar72, i32 0, i32 %tmpvar73
  %tmpvar75 = load i32, i32* %tmpvar74, align 4
  store i32 0, i32* %tmpvar74, align 4
  %tmpvar76 = load i32, i32* %k, align 4
  store i32 0, i32* %k, align 4
  %tmpvar80 = load i32, i32* %k, align 4
  %tmpvar81 = load i32, i32* %Na, align 4
  %tmpcmp82 = icmp slt i32 %tmpvar80, %tmpvar81
  br i1 %tmpcmp82, label %forloop79, label %forcont77

foradd66:                                         ; preds = %forcont77
  %tmpvar103 = load i32, i32* %j, align 4
  %tmpAdd104 = add i32 %tmpvar103, 1
  store volatile i32 %tmpAdd104, i32* %j, align 4
  %tmpvar105 = load i32, i32* %j, align 4
  %tmpvar106 = load i32, i32* %Nb, align 4
  %tmpcmp107 = icmp slt i32 %tmpvar105, %tmpvar106
  br i1 %tmpcmp107, label %forloop67, label %forcont65

forcont65:                                        ; preds = %foradd66, %forloop60
  br label %foradd59

forloop79:                                        ; preds = %foradd78, %forloop67
  %tmpvar83 = load i32, i32* %i, align 4
  %tmpvar84 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %C, i32 0, i32 %tmpvar83
  %tmpvar85 = load i32, i32* %j, align 4
  %tmpvar86 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar84, i32 0, i32 %tmpvar85
  %tmpvar87 = load i32, i32* %i, align 4
  %tmpvar88 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %A, i32 0, i32 %tmpvar87
  %tmpvar89 = load i32, i32* %k, align 4
  %tmpvar90 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar88, i32 0, i32 %tmpvar89
  %tmpvar91 = load i32, i32* %k, align 4
  %tmpvar92 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %B, i32 0, i32 %tmpvar91
  %tmpvar93 = load i32, i32* %j, align 4
  %tmpvar94 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar92, i32 0, i32 %tmpvar93
  %tmpvar95 = load i32, i32* %tmpvar90, align 4
  %tmpvar96 = load i32, i32* %tmpvar94, align 4
  %tmpmul = mul i32 %tmpvar95, %tmpvar96
  %tmpvar97 = load i32, i32* %tmpvar86, align 4
  %tmpadd = add i32 %tmpvar97, %tmpmul
  store i32 %tmpadd, i32* %tmpvar86, align 4
  br label %foradd78

foradd78:                                         ; preds = %forloop79
  %tmpvar98 = load i32, i32* %k, align 4
  %tmpAdd99 = add i32 %tmpvar98, 1
  store volatile i32 %tmpAdd99, i32* %k, align 4
  %tmpvar100 = load i32, i32* %k, align 4
  %tmpvar101 = load i32, i32* %Na, align 4
  %tmpcmp102 = icmp slt i32 %tmpvar100, %tmpvar101
  br i1 %tmpcmp102, label %forloop79, label %forcont77

forcont77:                                        ; preds = %foradd78, %forloop67
  br label %foradd66

forloop116:                                       ; preds = %foradd115, %forcont58
  %tmpvar120 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar124 = load i32, i32* %j, align 4
  %tmpvar125 = load i32, i32* %Nb, align 4
  %tmpcmp126 = icmp slt i32 %tmpvar124, %tmpvar125
  br i1 %tmpcmp126, label %forloop123, label %forcont121

foradd115:                                        ; preds = %forcont121
  %tmpvar139 = load i32, i32* %i, align 4
  %tmpAdd140 = add i32 %tmpvar139, 1
  store volatile i32 %tmpAdd140, i32* %i, align 4
  %tmpvar141 = load i32, i32* %i, align 4
  %tmpvar142 = load i32, i32* %Ma, align 4
  %tmpcmp143 = icmp slt i32 %tmpvar141, %tmpvar142
  br i1 %tmpcmp143, label %forloop116, label %forcont114

forcont114:                                       ; preds = %foradd115, %forcont58
  ret i32 0

forloop123:                                       ; preds = %foradd122, %forloop116
  %tmpvar127 = load i32, i32* %i, align 4
  %tmpvar128 = getelementptr inbounds [25 x [25 x i32]], [25 x [25 x i32]]* %C, i32 0, i32 %tmpvar127
  %tmpvar129 = load i32, i32* %j, align 4
  %tmpvar130 = getelementptr inbounds [25 x i32], [25 x i32]* %tmpvar128, i32 0, i32 %tmpvar129
  %tmpvar131 = load i32, i32* %tmpvar130, align 4
  %printf132 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.5, i32 0, i32 0), i32 %tmpvar131)
  br label %foradd122

foradd122:                                        ; preds = %forloop123
  %tmpvar133 = load i32, i32* %j, align 4
  %tmpAdd134 = add i32 %tmpvar133, 1
  store volatile i32 %tmpAdd134, i32* %j, align 4
  %tmpvar135 = load i32, i32* %j, align 4
  %tmpvar136 = load i32, i32* %Nb, align 4
  %tmpcmp137 = icmp slt i32 %tmpvar135, %tmpvar136
  br i1 %tmpcmp137, label %forloop123, label %forcont121

forcont121:                                       ; preds = %foradd122, %forloop116
  %printf138 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @_Const_String_.6, i32 0, i32 0))
  br label %foradd115
}
