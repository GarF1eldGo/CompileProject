; ModuleID = 'module'
source_filename = "module"

@_Const_String_ = private constant [7 x i8] c"%d %d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
main:
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %j, align 4
  %n = alloca i32, align 4
  store i32 5, i32* %n, align 4
  %tmpvar = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar1 = load i32, i32* %i, align 4
  %tmpvar2 = load i32, i32* %n, align 4
  %tmpcmp = icmp slt i32 %tmpvar1, %tmpvar2
  br i1 %tmpcmp, label %forloop, label %forcont

forloop:                                          ; preds = %foradd, %main
  %tmpvar3 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar7 = load i32, i32* %j, align 4
  %tmpvar8 = load i32, i32* %n, align 4
  %tmpcmp9 = icmp slt i32 %tmpvar7, %tmpvar8
  br i1 %tmpcmp9, label %forloop6, label %forcont4

foradd:                                           ; preds = %forcont4
  %tmpvar18 = load i32, i32* %i, align 4
  %tmpAdd19 = add i32 %tmpvar18, 1
  store volatile i32 %tmpAdd19, i32* %i, align 4
  %tmpvar20 = load i32, i32* %i, align 4
  %tmpvar21 = load i32, i32* %n, align 4
  %tmpcmp22 = icmp slt i32 %tmpvar20, %tmpvar21
  br i1 %tmpcmp22, label %forloop, label %forcont

forcont:                                          ; preds = %foradd, %main
  ret i32 0

forloop6:                                         ; preds = %foradd5, %forloop
  %tmpvar10 = load i32, i32* %j, align 4
  %tmpcmp11 = icmp eq i32 %tmpvar10, 3
  br i1 %tmpcmp11, label %then, label %else

foradd5:                                          ; preds = %merge
  %tmpvar14 = load i32, i32* %j, align 4
  %tmpAdd = add i32 %tmpvar14, 1
  store volatile i32 %tmpAdd, i32* %j, align 4
  %tmpvar15 = load i32, i32* %j, align 4
  %tmpvar16 = load i32, i32* %n, align 4
  %tmpcmp17 = icmp slt i32 %tmpvar15, %tmpvar16
  br i1 %tmpcmp17, label %forloop6, label %forcont4

forcont4:                                         ; preds = %foradd5, %then, %forloop
  br label %foradd

then:                                             ; preds = %forloop6
  br label %forcont4
  br label %merge

else:                                             ; preds = %forloop6
  br label %merge

merge:                                            ; preds = %else, %then
  %tmpvar12 = load i32, i32* %i, align 4
  %tmpvar13 = load i32, i32* %j, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @_Const_String_, i32 0, i32 0), i32 %tmpvar12, i32 %tmpvar13)
  br label %foradd5
}
