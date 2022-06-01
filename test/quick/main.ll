; ModuleID = 'module'
source_filename = "module"

@_Const_String_ = private constant [3 x i8] c"%d\00"
@_Const_String_.1 = private constant [3 x i8] c"%d\00"
@_Const_String_.2 = private constant [4 x i8] c"%d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define void @quickSort([100000 x i32]* %numArray, i32 %leftpara, i32 %rightpara) {
quickSort:
  %left = alloca i32, align 4
  store i32 %leftpara, i32* %left, align 4
  %right = alloca i32, align 4
  store i32 %rightpara, i32* %right, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %j, align 4
  %temp = alloca i32, align 4
  store i32 0, i32* %temp, align 4
  %key = alloca i32, align 4
  store i32 0, i32* %key, align 4
  %tmpvar = load i32, i32* %left, align 4
  %tmpvar1 = load i32, i32* %right, align 4
  %tmpcmp = icmp sge i32 %tmpvar, %tmpvar1
  br i1 %tmpcmp, label %then, label %else

then:                                             ; preds = %quickSort
  ret void
  br label %merge

else:                                             ; preds = %quickSort
  br label %merge

merge:                                            ; preds = %else, %then
  %tmpvar2 = load i32, i32* %left, align 4
  %tmpvar3 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar2
  %tmpvar4 = load i32, i32* %key, align 4
  %tmpvar5 = load i32, i32* %tmpvar3, align 4
  store i32 %tmpvar5, i32* %key, align 4
  %tmpvar6 = load i32, i32* %i, align 4
  %tmpvar7 = load i32, i32* %left, align 4
  store i32 %tmpvar7, i32* %i, align 4
  %tmpvar8 = load i32, i32* %j, align 4
  %tmpvar9 = load i32, i32* %right, align 4
  store i32 %tmpvar9, i32* %j, align 4
  %tmpvar10 = load i32, i32* %i, align 4
  %tmpvar11 = load i32, i32* %j, align 4
  %tmpcmp12 = icmp slt i32 %tmpvar10, %tmpvar11
  br i1 %tmpcmp12, label %whileloop, label %whilecont

whileloop:                                        ; preds = %whilecont40, %merge
  %tmpvar15 = load i32, i32* %i, align 4
  %tmpvar16 = load i32, i32* %j, align 4
  %tmpcmp17 = icmp slt i32 %tmpvar15, %tmpvar16
  %tmpvar18 = load i32, i32* %j, align 4
  %tmpvar19 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar18
  %tmpvar20 = load i32, i32* %tmpvar19, align 4
  %tmpvar21 = load i32, i32* %key, align 4
  %tmpcmp22 = icmp sge i32 %tmpvar20, %tmpvar21
  %tmpand = and i1 %tmpcmp17, %tmpcmp22
  br i1 %tmpand, label %whileloop13, label %whilecont14

whilecont:                                        ; preds = %whilecont40, %merge
  %tmpvar69 = load i32, i32* %i, align 4
  %tmpvar70 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar69
  %tmpvar71 = load i32, i32* %tmpvar70, align 4
  %tmpvar72 = load i32, i32* %key, align 4
  store i32 %tmpvar72, i32* %tmpvar70, align 4
  %tmpvar73 = load i32, i32* %i, align 4
  %tmpsub = sub i32 %tmpvar73, 1
  %tmpvar74 = load i32, i32* %left, align 4
  call void @quickSort([100000 x i32]* %numArray, i32 %tmpvar74, i32 %tmpsub)
  %tmpvar75 = load i32, i32* %i, align 4
  %tmpadd = add i32 %tmpvar75, 1
  %tmpvar76 = load i32, i32* %right, align 4
  call void @quickSort([100000 x i32]* %numArray, i32 %tmpadd, i32 %tmpvar76)
  ret void

whileloop13:                                      ; preds = %whileloop13, %whileloop
  %tmpvar23 = load i32, i32* %j, align 4
  %tmpSub = sub i32 %tmpvar23, 1
  store volatile i32 %tmpSub, i32* %j, align 4
  %tmpvar24 = load i32, i32* %i, align 4
  %tmpvar25 = load i32, i32* %j, align 4
  %tmpcmp26 = icmp slt i32 %tmpvar24, %tmpvar25
  %tmpvar27 = load i32, i32* %j, align 4
  %tmpvar28 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar27
  %tmpvar29 = load i32, i32* %tmpvar28, align 4
  %tmpvar30 = load i32, i32* %key, align 4
  %tmpcmp31 = icmp sge i32 %tmpvar29, %tmpvar30
  %tmpand32 = and i1 %tmpcmp26, %tmpcmp31
  br i1 %tmpand32, label %whileloop13, label %whilecont14

whilecont14:                                      ; preds = %whileloop13, %whileloop
  %tmpvar33 = load i32, i32* %i, align 4
  %tmpvar34 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar33
  %tmpvar35 = load i32, i32* %j, align 4
  %tmpvar36 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar35
  %tmpvar37 = load i32, i32* %tmpvar34, align 4
  %tmpvar38 = load i32, i32* %tmpvar36, align 4
  store i32 %tmpvar38, i32* %tmpvar34, align 4
  %tmpvar41 = load i32, i32* %i, align 4
  %tmpvar42 = load i32, i32* %j, align 4
  %tmpcmp43 = icmp slt i32 %tmpvar41, %tmpvar42
  %tmpvar44 = load i32, i32* %i, align 4
  %tmpvar45 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar44
  %tmpvar46 = load i32, i32* %tmpvar45, align 4
  %tmpvar47 = load i32, i32* %key, align 4
  %tmpcmp48 = icmp sle i32 %tmpvar46, %tmpvar47
  %tmpand49 = and i1 %tmpcmp43, %tmpcmp48
  br i1 %tmpand49, label %whileloop39, label %whilecont40

whileloop39:                                      ; preds = %whileloop39, %whilecont14
  %tmpvar50 = load i32, i32* %i, align 4
  %tmpAdd = add i32 %tmpvar50, 1
  store volatile i32 %tmpAdd, i32* %i, align 4
  %tmpvar51 = load i32, i32* %i, align 4
  %tmpvar52 = load i32, i32* %j, align 4
  %tmpcmp53 = icmp slt i32 %tmpvar51, %tmpvar52
  %tmpvar54 = load i32, i32* %i, align 4
  %tmpvar55 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar54
  %tmpvar56 = load i32, i32* %tmpvar55, align 4
  %tmpvar57 = load i32, i32* %key, align 4
  %tmpcmp58 = icmp sle i32 %tmpvar56, %tmpvar57
  %tmpand59 = and i1 %tmpcmp53, %tmpcmp58
  br i1 %tmpand59, label %whileloop39, label %whilecont40

whilecont40:                                      ; preds = %whileloop39, %whilecont14
  %tmpvar60 = load i32, i32* %j, align 4
  %tmpvar61 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar60
  %tmpvar62 = load i32, i32* %i, align 4
  %tmpvar63 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar62
  %tmpvar64 = load i32, i32* %tmpvar61, align 4
  %tmpvar65 = load i32, i32* %tmpvar63, align 4
  store i32 %tmpvar65, i32* %tmpvar61, align 4
  %tmpvar66 = load i32, i32* %i, align 4
  %tmpvar67 = load i32, i32* %j, align 4
  %tmpcmp68 = icmp slt i32 %tmpvar66, %tmpvar67
  br i1 %tmpcmp68, label %whileloop, label %whilecont
}

define i32 @main() {
main:
  %num = alloca i32, align 4
  store i32 0, i32* %num, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %numArray = alloca [100000 x i32], align 4
  %scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_, i32 0, i32 0), i32* %num)
  %tmpvar = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar1 = load i32, i32* %i, align 4
  %tmpvar2 = load i32, i32* %num, align 4
  %tmpcmp = icmp slt i32 %tmpvar1, %tmpvar2
  br i1 %tmpcmp, label %forloop, label %forcont

forloop:                                          ; preds = %foradd, %main
  %tmpvar3 = load i32, i32* %i, align 4
  %tmpvar4 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar3
  %scanf5 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.1, i32 0, i32 0), i32* %tmpvar4)
  br label %foradd

foradd:                                           ; preds = %forloop
  %tmpvar6 = load i32, i32* %i, align 4
  %tmpAdd = add i32 %tmpvar6, 1
  store volatile i32 %tmpAdd, i32* %i, align 4
  %tmpvar7 = load i32, i32* %i, align 4
  %tmpvar8 = load i32, i32* %num, align 4
  %tmpcmp9 = icmp slt i32 %tmpvar7, %tmpvar8
  br i1 %tmpcmp9, label %forloop, label %forcont

forcont:                                          ; preds = %foradd, %main
  %tmpvar10 = load i32, i32* %num, align 4
  %tmpsub = sub i32 %tmpvar10, 1
  call void @quickSort([100000 x i32]* %numArray, i32 0, i32 %tmpsub)
  %tmpvar11 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar15 = load i32, i32* %i, align 4
  %tmpvar16 = load i32, i32* %num, align 4
  %tmpcmp17 = icmp slt i32 %tmpvar15, %tmpvar16
  br i1 %tmpcmp17, label %forloop14, label %forcont12

forloop14:                                        ; preds = %foradd13, %forcont
  %tmpvar18 = load i32, i32* %i, align 4
  %tmpvar19 = getelementptr inbounds [100000 x i32], [100000 x i32]* %numArray, i32 0, i32 %tmpvar18
  %tmpvar20 = load i32, i32* %tmpvar19, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.2, i32 0, i32 0), i32 %tmpvar20)
  br label %foradd13

foradd13:                                         ; preds = %forloop14
  %tmpvar21 = load i32, i32* %i, align 4
  %tmpAdd22 = add i32 %tmpvar21, 1
  store volatile i32 %tmpAdd22, i32* %i, align 4
  %tmpvar23 = load i32, i32* %i, align 4
  %tmpvar24 = load i32, i32* %num, align 4
  %tmpcmp25 = icmp slt i32 %tmpvar23, %tmpvar24
  br i1 %tmpcmp25, label %forloop14, label %forcont12

forcont12:                                        ; preds = %foradd13, %forcont
  ret i32 0
}
