; ModuleID = 'advisor/main-obfuscate.bc'
source_filename = "module"

@preCourse = global [100 x [200 x i8]] zeroinitializer
@_Const_String_ = private global [3 x i8] c"\0FI\00"
@_Const_String_.1 = private global [3 x i8] c"\0FI\00"
@_Const_String_.2 = private global [12 x i8] c"mzk\10\0A\0F\1A\04\1BL \00"
@_Const_String_.3 = private global [21 x i8] c"bE_XY\0Ak^^OGZ^ON\10\0A\0FN \00"
@_Const_String_.4 = private global [21 x i8] c"bE_XY\0AiEGZFO^ON\10\0A\0FN \00"
@_Const_String_.5 = private global [24 x i8] c"iXONC^Y\0AxOGKCDCDM\10\0A\0FN  \00"
@_Const_String_.6 = private global [31 x i8] c"zEYYCHFO\0AiE_XYOY\0A^E\0A~KAO\0AdOR^ \00"
@_Const_String_.7 = private global [27 x i8] c"\0A\0AdEDO\0A\07\0AiEDMXK^_FK^CEDY\0B \00"
@_Const_String_.8 = private global [5 x i8] c"\0FI\0FI\00"
@_Const_String_.9 = private global [3 x i8] c"\0FI\00"
@_Const_String_.10 = private global [3 x i8] c"\0FI\00"
@_Const_String_.11 = private global [5 x i8] c"\0FI\0FI\00"
@_Const_String_.12 = private global [3 x i8] c"\0FI\00"
@_Const_String_.13 = private global [3 x i8] c"\0FI\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @myStrcmp([100 x i8]* %preCourseName, i32 %len1para, [100 x [100 x i8]]* %takenCourseName, i32 %len2para) {
myStrcmp:
  %len1 = alloca i32, align 4
  store i32 %len1para, i32* %len1, align 4
  %len2 = alloca i32, align 4
  store i32 %len2para, i32* %len2, align 4
  %flag = alloca i32, align 4
  store i32 1, i32* %flag, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %j, align 4
  %tmpvar = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar1 = load i32, i32* %i, align 4
  %tmpvar2 = load i32, i32* %len2, align 4
  %tmpcmp = icmp slt i32 %tmpvar1, %tmpvar2
  br i1 %tmpcmp, label %forloop, label %forcont

forloop:                                          ; preds = %foradd, %myStrcmp
  %tmpvar3 = load i32, i32* %flag, align 4
  store i32 1, i32* %flag, align 4
  %tmpvar4 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar8 = load i32, i32* %j, align 4
  %tmpcmp9 = icmp slt i32 %tmpvar8, 5
  br i1 %tmpcmp9, label %forloop7, label %forcont5

foradd:                                           ; preds = %merge54
  %tmpvar57 = load i32, i32* %i, align 4
  %tmpAdd58 = add i32 %tmpvar57, 1
  store volatile i32 %tmpAdd58, i32* %i, align 4
  %tmpvar59 = load i32, i32* %i, align 4
  %tmpvar60 = load i32, i32* %len2, align 4
  %tmpcmp61 = icmp slt i32 %tmpvar59, %tmpvar60
  br i1 %tmpcmp61, label %forloop, label %forcont

forcont:                                          ; preds = %foradd, %myStrcmp
  ret i32 0

forloop7:                                         ; preds = %foradd6, %forloop
  %tmpvar10 = load i32, i32* %j, align 4
  %tmpvar11 = getelementptr inbounds [100 x i8], [100 x i8]* %preCourseName, i32 0, i32 %tmpvar10
  %tmpvar12 = load i8, i8* %tmpvar11, align 1
  %tmpcmp13 = icmp eq i8 %tmpvar12, 0
  %tmpvar14 = load i32, i32* %i, align 4
  %tmpvar15 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %takenCourseName, i32 0, i32 %tmpvar14
  %tmpvar16 = load i32, i32* %j, align 4
  %tmpvar17 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar15, i32 0, i32 %tmpvar16
  %tmpvar18 = load i8, i8* %tmpvar17, align 1
  %tmpcmp19 = icmp ne i8 %tmpvar18, 0
  %tmpand = and i1 %tmpcmp13, %tmpcmp19
  br i1 %tmpand, label %then, label %else

foradd6:                                          ; preds = %merge
  %tmpvar49 = load i32, i32* %j, align 4
  %tmpAdd = add i32 %tmpvar49, 1
  store volatile i32 %tmpAdd, i32* %j, align 4
  %tmpvar50 = load i32, i32* %j, align 4
  %tmpcmp51 = icmp slt i32 %tmpvar50, 5
  br i1 %tmpcmp51, label %forloop7, label %forcont5

forcont5:                                         ; preds = %foradd6, %forloop
  %tmpvar55 = load i32, i32* %flag, align 4
  %tmpcmp56 = icmp sgt i32 %tmpvar55, 0
  br i1 %tmpcmp56, label %then52, label %else53

then:                                             ; preds = %forloop7
  %tmpvar20 = load i32, i32* %flag, align 4
  store i32 0, i32* %flag, align 4
  br label %merge

else:                                             ; preds = %forloop7
  %tmpvar24 = load i32, i32* %j, align 4
  %tmpvar25 = getelementptr inbounds [100 x i8], [100 x i8]* %preCourseName, i32 0, i32 %tmpvar24
  %tmpvar26 = load i8, i8* %tmpvar25, align 1
  %tmpcmp27 = icmp ne i8 %tmpvar26, 0
  %tmpvar28 = load i32, i32* %i, align 4
  %tmpvar29 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %takenCourseName, i32 0, i32 %tmpvar28
  %tmpvar30 = load i32, i32* %j, align 4
  %tmpvar31 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar29, i32 0, i32 %tmpvar30
  %tmpvar32 = load i8, i8* %tmpvar31, align 1
  %tmpcmp33 = icmp eq i8 %tmpvar32, 0
  %tmpand34 = and i1 %tmpcmp27, %tmpcmp33
  br i1 %tmpand34, label %then21, label %else22

merge:                                            ; preds = %merge23, %then
  br label %foradd6

then21:                                           ; preds = %else
  %tmpvar35 = load i32, i32* %flag, align 4
  store i32 0, i32* %flag, align 4
  br label %merge23

else22:                                           ; preds = %else
  %tmpvar39 = load i32, i32* %i, align 4
  %tmpvar40 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %takenCourseName, i32 0, i32 %tmpvar39
  %tmpvar41 = load i32, i32* %j, align 4
  %tmpvar42 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar40, i32 0, i32 %tmpvar41
  %tmpvar43 = load i32, i32* %j, align 4
  %tmpvar44 = getelementptr inbounds [100 x i8], [100 x i8]* %preCourseName, i32 0, i32 %tmpvar43
  %tmpvar45 = load i8, i8* %tmpvar42, align 1
  %tmpvar46 = load i8, i8* %tmpvar44, align 1
  %tmpcmp47 = icmp ne i8 %tmpvar45, %tmpvar46
  br i1 %tmpcmp47, label %then36, label %else37

merge23:                                          ; preds = %merge38, %then21
  br label %merge

then36:                                           ; preds = %else22
  %tmpvar48 = load i32, i32* %flag, align 4
  store i32 0, i32* %flag, align 4
  br label %merge38

else37:                                           ; preds = %else22
  br label %merge38

merge38:                                          ; preds = %else37, %then36
  br label %merge23

then52:                                           ; preds = %forcont5
  ret i32 1

0:                                                ; No predecessors!
  br label %merge54

else53:                                           ; preds = %forcont5
  br label %merge54

merge54:                                          ; preds = %else53, %0
  br label %foradd
}

define i32 @boolExpression([100 x i8]* %name, [100 x i8]* %token, i32 %begin1para, i32 %len1para, [100 x i32]* %preCourseTrue, i32 %begin2para, i32 %len2para) {
boolExpression:
  %begin1 = alloca i32, align 4
  store i32 %begin1para, i32* %begin1, align 4
  %len1 = alloca i32, align 4
  store i32 %len1para, i32* %len1, align 4
  %begin2 = alloca i32, align 4
  store i32 %begin2para, i32* %begin2, align 4
  %len2 = alloca i32, align 4
  store i32 %len2para, i32* %len2, align 4
  %tmpvar = load i32, i32* %begin2, align 4
  %tmpvar1 = getelementptr inbounds [100 x i32], [100 x i32]* %preCourseTrue, i32 0, i32 %tmpvar
  %tmpvar2 = load i32, i32* %tmpvar1, align 4
  %result = alloca i32, align 4
  store i32 %tmpvar2, i32* %result, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %j, align 4
  %tmpvar3 = load i32, i32* %begin2, align 4
  %tmpadd = add i32 %tmpvar3, 1
  %courseIndex = alloca i32, align 4
  store i32 %tmpadd, i32* %courseIndex, align 4
  %flag = alloca i32, align 4
  store i32 1, i32* %flag, align 4
  %tmpvar4 = load i32, i32* %i, align 4
  %tmpvar5 = load i32, i32* %begin1, align 4
  store i32 %tmpvar5, i32* %i, align 4
  %tmpvar6 = load i32, i32* %i, align 4
  %tmpvar7 = load i32, i32* %len1, align 4
  %tmpcmp = icmp slt i32 %tmpvar6, %tmpvar7
  %tmpvar8 = load i32, i32* %flag, align 4
  %tmpcmp9 = icmp eq i32 %tmpvar8, 1
  %tmpand = and i1 %tmpcmp, %tmpcmp9
  br i1 %tmpand, label %forloop, label %forcont

forloop:                                          ; preds = %foradd, %boolExpression
  %tmpvar10 = load i32, i32* %i, align 4
  %tmpvar11 = getelementptr inbounds [100 x i8], [100 x i8]* %token, i32 0, i32 %tmpvar10
  %tmpvar12 = load i8, i8* %tmpvar11, align 1
  %tmpcmp13 = icmp eq i8 %tmpvar12, 44
  br i1 %tmpcmp13, label %then, label %else

foradd:                                           ; preds = %merge
  %tmpvar47 = load i32, i32* %i, align 4
  %tmpAdd48 = add i32 %tmpvar47, 1
  store volatile i32 %tmpAdd48, i32* %i, align 4
  %tmpvar49 = load i32, i32* %i, align 4
  %tmpvar50 = load i32, i32* %len1, align 4
  %tmpcmp51 = icmp slt i32 %tmpvar49, %tmpvar50
  %tmpvar52 = load i32, i32* %flag, align 4
  %tmpcmp53 = icmp eq i32 %tmpvar52, 1
  %tmpand54 = and i1 %tmpcmp51, %tmpcmp53
  br i1 %tmpand54, label %forloop, label %forcont

forcont:                                          ; preds = %foradd, %boolExpression
  %tmpvar55 = load i32, i32* %result, align 4
  ret i32 %tmpvar55

then:                                             ; preds = %forloop
  %tmpvar17 = load i32, i32* %result, align 4
  %tmpcmp18 = icmp eq i32 %tmpvar17, 1
  %tmpvar19 = load i32, i32* %courseIndex, align 4
  %tmpvar20 = getelementptr inbounds [100 x i32], [100 x i32]* %preCourseTrue, i32 0, i32 %tmpvar19
  %tmpvar21 = load i32, i32* %tmpvar20, align 4
  %tmpcmp22 = icmp eq i32 %tmpvar21, 1
  %tmpand23 = and i1 %tmpcmp18, %tmpcmp22
  br i1 %tmpand23, label %then14, label %else15

else:                                             ; preds = %forloop
  %tmpvar30 = load i32, i32* %i, align 4
  %tmpvar31 = getelementptr inbounds [100 x i8], [100 x i8]* %token, i32 0, i32 %tmpvar30
  %tmpvar32 = load i8, i8* %tmpvar31, align 1
  %tmpcmp33 = icmp eq i8 %tmpvar32, 59
  br i1 %tmpcmp33, label %then27, label %else28

merge:                                            ; preds = %merge29, %merge16
  br label %foradd

then14:                                           ; preds = %then
  %tmpvar24 = load i32, i32* %result, align 4
  store i32 1, i32* %result, align 4
  br label %merge16

else15:                                           ; preds = %then
  %tmpvar25 = load i32, i32* %result, align 4
  store i32 0, i32* %result, align 4
  br label %merge16

merge16:                                          ; preds = %else15, %then14
  %tmpvar26 = load i32, i32* %courseIndex, align 4
  %tmpAdd = add i32 %tmpvar26, 1
  store volatile i32 %tmpAdd, i32* %courseIndex, align 4
  br label %merge

then27:                                           ; preds = %else
  %tmpvar37 = load i32, i32* %result, align 4
  %tmpcmp38 = icmp eq i32 %tmpvar37, 1
  %tmpvar39 = load i32, i32* %i, align 4
  %tmpadd40 = add i32 %tmpvar39, 1
  %tmpvar41 = load i32, i32* %len1, align 4
  %tmpvar42 = load i32, i32* %courseIndex, align 4
  %tmpvar43 = load i32, i32* %len2, align 4
  %tmpcall = call i32 @boolExpression([100 x i8]* %name, [100 x i8]* %token, i32 %tmpadd40, i32 %tmpvar41, [100 x i32]* %preCourseTrue, i32 %tmpvar42, i32 %tmpvar43)
  %tmpcmp44 = icmp eq i32 %tmpcall, 1
  %tmpor = or i1 %tmpcmp38, %tmpcmp44
  br i1 %tmpor, label %then34, label %else35

else28:                                           ; preds = %else
  br label %merge29

merge29:                                          ; preds = %merge36, %else28
  br label %merge

then34:                                           ; preds = %then27
  %tmpvar45 = load i32, i32* %result, align 4
  store i32 1, i32* %result, align 4
  br label %merge36

else35:                                           ; preds = %then27
  br label %merge36

merge36:                                          ; preds = %else35, %then34
  %tmpvar46 = load i32, i32* %flag, align 4
  store i32 0, i32* %flag, align 4
  br label %merge29
}

define i32 @main() {
main:
  %maxNum = alloca i32, align 4
  store i32 100, i32* %maxNum, align 4
  %maxInput = alloca i32, align 4
  store i32 100, i32* %maxInput, align 4
  %nameLen = alloca i32, align 4
  store i32 5, i32* %nameLen, align 4
  %courseName = alloca [100 x [100 x i8]], align 1
  %credit = alloca [100 x i32], align 4
  %score = alloca [100 x i32], align 4
  %curNum = alloca i32, align 4
  store i32 0, i32* %curNum, align 4
  %emptyLine = alloca i32, align 4
  store i32 0, i32* %emptyLine, align 4
  %inputStr = alloca [500 x i8], align 1
  %tempIndex = alloca i32, align 4
  store i32 1, i32* %tempIndex, align 4
  %newLine = alloca i32, align 4
  store i32 0, i32* %newLine, align 4
  %curIndex = alloca i32, align 4
  store i32 0, i32* %curIndex, align 4
  %index = alloca i32, align 4
  store i32 0, i32* %index, align 4
  %gpa = alloca float, align 4
  store float 0.000000e+00, float* %gpa, align 4
  %tryCredit = alloca i32, align 4
  store i32 0, i32* %tryCredit, align 4
  %takenCredit = alloca i32, align 4
  store i32 0, i32* %takenCredit, align 4
  %remainCredit = alloca i32, align 4
  store i32 0, i32* %remainCredit, align 4
  %takenCourseName = alloca [100 x [100 x i8]], align 1
  %takenIndex = alloca i32, align 4
  store i32 0, i32* %takenIndex, align 4
  %untakenCourseIndex = alloca [100 x i32], align 4
  %untakenIndex = alloca i32, align 4
  store i32 0, i32* %untakenIndex, align 4
  %creditNum = alloca i32, align 4
  store i32 0, i32* %creditNum, align 4
  %scoreNum = alloca float, align 4
  store float 0.000000e+00, float* %scoreNum, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %j, align 4
  %ii = alloca i32, align 4
  store i32 0, i32* %ii, align 4
  %iii = alloca i32, align 4
  store i32 0, i32* %iii, align 4
  %preCourseTrue = alloca [100 x i32], align 4
  %trueIndex = alloca i32, align 4
  store i32 0, i32* %trueIndex, align 4
  %token = alloca [100 x i8], align 1
  %tokenIndex = alloca i32, align 4
  store i32 0, i32* %tokenIndex, align 4
  %result = alloca i32, align 4
  store i32 0, i32* %result, align 4
  %tempName = alloca [100 x i8], align 1
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %k = alloca i32, align 4
  store i32 0, i32* %k, align 4
  %tmpvar = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar1 = load i32, i32* %i, align 4
  %tmpcmp = icmp slt i32 %tmpvar1, 100
  br i1 %tmpcmp, label %forloop, label %forcont

forloop:                                          ; preds = %foradd, %main
  %tmpvar2 = load i32, i32* %i, align 4
  %tmpvar3 = getelementptr inbounds [100 x i32], [100 x i32]* %credit, i32 0, i32 %tmpvar2
  %tmpvar4 = load i32, i32* %tmpvar3, align 4
  store i32 0, i32* %tmpvar3, align 4
  %tmpvar5 = load i32, i32* %i, align 4
  %tmpvar6 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar5
  %tmpvar7 = load i32, i32* %tmpvar6, align 4
  store i32 0, i32* %tmpvar6, align 4
  %tmpvar8 = load i32, i32* %i, align 4
  %tmpvar9 = getelementptr inbounds [100 x i32], [100 x i32]* %untakenCourseIndex, i32 0, i32 %tmpvar8
  %tmpvar10 = load i32, i32* %tmpvar9, align 4
  store i32 0, i32* %tmpvar9, align 4
  %tmpvar11 = load i32, i32* %i, align 4
  %tmpvar12 = getelementptr inbounds [100 x i32], [100 x i32]* %preCourseTrue, i32 0, i32 %tmpvar11
  %tmpvar13 = load i32, i32* %tmpvar12, align 4
  store i32 0, i32* %tmpvar12, align 4
  %tmpvar14 = load i32, i32* %i, align 4
  %tmpvar15 = getelementptr inbounds [100 x i8], [100 x i8]* %token, i32 0, i32 %tmpvar14
  %tmpvar16 = load i8, i8* %tmpvar15, align 1
  store i8 0, i8* %tmpvar15, align 1
  br label %foradd

foradd:                                           ; preds = %forloop
  %tmpvar17 = load i32, i32* %i, align 4
  %tmpAdd = add i32 %tmpvar17, 1
  store volatile i32 %tmpAdd, i32* %i, align 4
  %tmpvar18 = load i32, i32* %i, align 4
  %tmpcmp19 = icmp slt i32 %tmpvar18, 100
  br i1 %tmpcmp19, label %forloop, label %forcont

forcont:                                          ; preds = %foradd, %main
  %tmpvar20 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar24 = load i32, i32* %i, align 4
  %tmpcmp25 = icmp slt i32 %tmpvar24, 100
  br i1 %tmpcmp25, label %forloop23, label %forcont21

forloop23:                                        ; preds = %foradd22, %forcont
  %tmpvar26 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar30 = load i32, i32* %j, align 4
  %tmpcmp31 = icmp slt i32 %tmpvar30, 5
  br i1 %tmpcmp31, label %forloop29, label %forcont27

foradd22:                                         ; preds = %forcont27
  %tmpvar46 = load i32, i32* %i, align 4
  %tmpAdd47 = add i32 %tmpvar46, 1
  store volatile i32 %tmpAdd47, i32* %i, align 4
  %tmpvar48 = load i32, i32* %i, align 4
  %tmpcmp49 = icmp slt i32 %tmpvar48, 100
  br i1 %tmpcmp49, label %forloop23, label %forcont21

forcont21:                                        ; preds = %foradd22, %forcont
  %tmpvar50 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar54 = load i32, i32* %i, align 4
  %tmpcmp55 = icmp slt i32 %tmpvar54, 100
  br i1 %tmpcmp55, label %forloop53, label %forcont51

forloop29:                                        ; preds = %foradd28, %forloop23
  %tmpvar32 = load i32, i32* %i, align 4
  %tmpvar33 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar32
  %tmpvar34 = load i32, i32* %j, align 4
  %tmpvar35 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar33, i32 0, i32 %tmpvar34
  %tmpvar36 = load i8, i8* %tmpvar35, align 1
  store i8 0, i8* %tmpvar35, align 1
  %tmpvar37 = load i32, i32* %i, align 4
  %tmpvar38 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %takenCourseName, i32 0, i32 %tmpvar37
  %tmpvar39 = load i32, i32* %j, align 4
  %tmpvar40 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar38, i32 0, i32 %tmpvar39
  %tmpvar41 = load i8, i8* %tmpvar40, align 1
  store i8 0, i8* %tmpvar40, align 1
  br label %foradd28

foradd28:                                         ; preds = %forloop29
  %tmpvar42 = load i32, i32* %j, align 4
  %tmpAdd43 = add i32 %tmpvar42, 1
  store volatile i32 %tmpAdd43, i32* %j, align 4
  %tmpvar44 = load i32, i32* %j, align 4
  %tmpcmp45 = icmp slt i32 %tmpvar44, 5
  br i1 %tmpcmp45, label %forloop29, label %forcont27

forcont27:                                        ; preds = %foradd28, %forloop23
  br label %foradd22

forloop53:                                        ; preds = %foradd52, %forcont21
  %tmpvar56 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar60 = load i32, i32* %j, align 4
  %tmpcmp61 = icmp slt i32 %tmpvar60, 200
  br i1 %tmpcmp61, label %forloop59, label %forcont57

foradd52:                                         ; preds = %forcont57
  %tmpvar71 = load i32, i32* %i, align 4
  %tmpAdd72 = add i32 %tmpvar71, 1
  store volatile i32 %tmpAdd72, i32* %i, align 4
  %tmpvar73 = load i32, i32* %i, align 4
  %tmpcmp74 = icmp slt i32 %tmpvar73, 100
  br i1 %tmpcmp74, label %forloop53, label %forcont51

forcont51:                                        ; preds = %foradd52, %forcont21
  %tmpvar75 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar79 = load i32, i32* %i, align 4
  %tmpcmp80 = icmp slt i32 %tmpvar79, 300
  br i1 %tmpcmp80, label %forloop78, label %forcont76

forloop59:                                        ; preds = %foradd58, %forloop53
  %tmpvar62 = load i32, i32* %i, align 4
  %tmpvar63 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar62
  %tmpvar64 = load i32, i32* %j, align 4
  %tmpvar65 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar63, i32 0, i32 %tmpvar64
  %tmpvar66 = load i8, i8* %tmpvar65, align 1
  store i8 0, i8* %tmpvar65, align 1
  br label %foradd58

foradd58:                                         ; preds = %forloop59
  %tmpvar67 = load i32, i32* %j, align 4
  %tmpAdd68 = add i32 %tmpvar67, 1
  store volatile i32 %tmpAdd68, i32* %j, align 4
  %tmpvar69 = load i32, i32* %j, align 4
  %tmpcmp70 = icmp slt i32 %tmpvar69, 200
  br i1 %tmpcmp70, label %forloop59, label %forcont57

forcont57:                                        ; preds = %foradd58, %forloop53
  br label %foradd52

forloop78:                                        ; preds = %foradd77, %forcont51
  %tmpvar81 = load i32, i32* %i, align 4
  %tmpvar82 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar81
  %tmpvar83 = load i8, i8* %tmpvar82, align 1
  store i8 0, i8* %tmpvar82, align 1
  br label %foradd77

foradd77:                                         ; preds = %forloop78
  %tmpvar84 = load i32, i32* %i, align 4
  %tmpAdd85 = add i32 %tmpvar84, 1
  store volatile i32 %tmpAdd85, i32* %i, align 4
  %tmpvar86 = load i32, i32* %i, align 4
  %tmpcmp87 = icmp slt i32 %tmpvar86, 300
  br i1 %tmpcmp87, label %forloop78, label %forcont76

forcont76:                                        ; preds = %foradd77, %forcont51
  %tmpvar88 = load i32, i32* %emptyLine, align 4
  %tmpcmp89 = icmp eq i32 %tmpvar88, 0
  br i1 %tmpcmp89, label %whileloop, label %whilecont

whileloop:                                        ; preds = %merge, %forcont76
  %tmpvar90 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar94 = load i32, i32* %i, align 4
  %tmpcmp95 = icmp slt i32 %tmpvar94, 300
  br i1 %tmpcmp95, label %forloop93, label %forcont91

whilecont:                                        ; preds = %merge, %forcont76
  %tmpvar266 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar270 = load i32, i32* %i, align 4
  %tmpvar271 = load i32, i32* %curNum, align 4
  %tmpcmp272 = icmp slt i32 %tmpvar270, %tmpvar271
  br i1 %tmpcmp272, label %forloop269, label %forcont267

forloop93:                                        ; preds = %foradd92, %whileloop
  %tmpvar96 = load i32, i32* %i, align 4
  %tmpvar97 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar96
  %tmpvar98 = load i8, i8* %tmpvar97, align 1
  store i8 0, i8* %tmpvar97, align 1
  br label %foradd92

foradd92:                                         ; preds = %forloop93
  %tmpvar99 = load i32, i32* %i, align 4
  %tmpAdd100 = add i32 %tmpvar99, 1
  store volatile i32 %tmpAdd100, i32* %i, align 4
  %tmpvar101 = load i32, i32* %i, align 4
  %tmpcmp102 = icmp slt i32 %tmpvar101, 300
  br i1 %tmpcmp102, label %forloop93, label %forcont91

forcont91:                                        ; preds = %foradd92, %whileloop
  %tmpvar103 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 0
  %0 = call i8* @__decrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_, i32 0, i32 0))
  %scanf = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_, i32 0, i32 0), i8* %tmpvar103)
  %1 = call i8* @__encrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_, i32 0, i32 0))
  %tmpvar104 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 0
  %tmpvar105 = load i8, i8* %tmpvar104, align 1
  %tmpcmp106 = icmp eq i8 %tmpvar105, 10
  br i1 %tmpcmp106, label %then, label %else

then:                                             ; preds = %forcont91
  %tmpvar107 = load i32, i32* %emptyLine, align 4
  store i32 1, i32* %emptyLine, align 4
  br label %merge

else:                                             ; preds = %forcont91
  %tmpvar108 = load i32, i32* %tempIndex, align 4
  store i32 1, i32* %tempIndex, align 4
  %tmpvar109 = load i32, i32* %newLine, align 4
  store i32 0, i32* %newLine, align 4
  %tmpvar112 = load i32, i32* %newLine, align 4
  %tmpcmp113 = icmp eq i32 %tmpvar112, 0
  br i1 %tmpcmp113, label %whileloop110, label %whilecont111

merge:                                            ; preds = %merge204, %then
  %tmpvar264 = load i32, i32* %emptyLine, align 4
  %tmpcmp265 = icmp eq i32 %tmpvar264, 0
  br i1 %tmpcmp265, label %whileloop, label %whilecont

whileloop110:                                     ; preds = %merge121, %else
  %tmpvar114 = load i32, i32* %tempIndex, align 4
  %tmpvar115 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar114
  %2 = call i8* @__decrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.1, i32 0, i32 0))
  %scanf116 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.1, i32 0, i32 0), i8* %tmpvar115)
  %3 = call i8* @__encrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.1, i32 0, i32 0))
  %tmpvar117 = load i32, i32* %tempIndex, align 4
  %tmpAdd118 = add i32 %tmpvar117, 1
  store volatile i32 %tmpAdd118, i32* %tempIndex, align 4
  %tmpvar122 = load i32, i32* %tempIndex, align 4
  %tmpsub = sub i32 %tmpvar122, 1
  %tmpvar123 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpsub
  %tmpvar124 = load i8, i8* %tmpvar123, align 1
  %tmpcmp125 = icmp eq i8 %tmpvar124, 10
  br i1 %tmpcmp125, label %then119, label %else120

whilecont111:                                     ; preds = %merge121, %else
  %tmpvar133 = load i32, i32* %curIndex, align 4
  store i32 0, i32* %curIndex, align 4
  %tmpvar136 = load i32, i32* %curIndex, align 4
  %tmpvar137 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar136
  %tmpvar138 = load i8, i8* %tmpvar137, align 1
  %tmpcmp139 = icmp ne i8 %tmpvar138, 124
  br i1 %tmpcmp139, label %whileloop134, label %whilecont135

then119:                                          ; preds = %whileloop110
  %tmpvar126 = load i32, i32* %tempIndex, align 4
  %tmpsub127 = sub i32 %tmpvar126, 1
  %tmpvar128 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpsub127
  %tmpvar129 = load i8, i8* %tmpvar128, align 1
  store i8 0, i8* %tmpvar128, align 1
  %tmpvar130 = load i32, i32* %newLine, align 4
  store i32 1, i32* %newLine, align 4
  br label %merge121

else120:                                          ; preds = %whileloop110
  br label %merge121

merge121:                                         ; preds = %else120, %then119
  %tmpvar131 = load i32, i32* %newLine, align 4
  %tmpcmp132 = icmp eq i32 %tmpvar131, 0
  br i1 %tmpcmp132, label %whileloop110, label %whilecont111

whileloop134:                                     ; preds = %whileloop134, %whilecont111
  %tmpvar140 = load i32, i32* %curNum, align 4
  %tmpvar141 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar140
  %tmpvar142 = load i32, i32* %curIndex, align 4
  %tmpvar143 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar141, i32 0, i32 %tmpvar142
  %tmpvar144 = load i32, i32* %curIndex, align 4
  %tmpvar145 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar144
  %tmpvar146 = load i8, i8* %tmpvar143, align 1
  %tmpvar147 = load i8, i8* %tmpvar145, align 1
  store i8 %tmpvar147, i8* %tmpvar143, align 1
  %tmpvar148 = load i32, i32* %curIndex, align 4
  %tmpAdd149 = add i32 %tmpvar148, 1
  store volatile i32 %tmpAdd149, i32* %curIndex, align 4
  %tmpvar150 = load i32, i32* %curIndex, align 4
  %tmpvar151 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar150
  %tmpvar152 = load i8, i8* %tmpvar151, align 1
  %tmpcmp153 = icmp ne i8 %tmpvar152, 124
  br i1 %tmpcmp153, label %whileloop134, label %whilecont135

whilecont135:                                     ; preds = %whileloop134, %whilecont111
  %tmpvar154 = load i32, i32* %curIndex, align 4
  %tmpAdd155 = add i32 %tmpvar154, 1
  store volatile i32 %tmpAdd155, i32* %curIndex, align 4
  %tmpvar158 = load i32, i32* %curIndex, align 4
  %tmpvar159 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar158
  %tmpvar160 = load i8, i8* %tmpvar159, align 1
  %tmpcmp161 = icmp ne i8 %tmpvar160, 124
  br i1 %tmpcmp161, label %whileloop156, label %whilecont157

whileloop156:                                     ; preds = %whileloop156, %whilecont135
  %tmpvar162 = load i32, i32* %curNum, align 4
  %tmpvar163 = getelementptr inbounds [100 x i32], [100 x i32]* %credit, i32 0, i32 %tmpvar162
  %tmpvar164 = load i32, i32* %curIndex, align 4
  %tmpvar165 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar164
  %tmpvar166 = load i8, i8* %tmpvar165, align 1
  %tmptypecast = zext i8 %tmpvar166 to i32
  %tmpsub167 = sub i32 %tmptypecast, 48
  %tmpvar168 = load i32, i32* %tmpvar163, align 4
  store i32 %tmpsub167, i32* %tmpvar163, align 4
  %tmpvar169 = load i32, i32* %curIndex, align 4
  %tmpAdd170 = add i32 %tmpvar169, 1
  store volatile i32 %tmpAdd170, i32* %curIndex, align 4
  %tmpvar171 = load i32, i32* %curIndex, align 4
  %tmpvar172 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar171
  %tmpvar173 = load i8, i8* %tmpvar172, align 1
  %tmpcmp174 = icmp ne i8 %tmpvar173, 124
  br i1 %tmpcmp174, label %whileloop156, label %whilecont157

whilecont157:                                     ; preds = %whileloop156, %whilecont135
  %tmpvar175 = load i32, i32* %curIndex, align 4
  %tmpAdd176 = add i32 %tmpvar175, 1
  store volatile i32 %tmpAdd176, i32* %curIndex, align 4
  %tmpvar177 = load i32, i32* %index, align 4
  store i32 0, i32* %index, align 4
  %tmpvar180 = load i32, i32* %curIndex, align 4
  %tmpvar181 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar180
  %tmpvar182 = load i8, i8* %tmpvar181, align 1
  %tmpcmp183 = icmp ne i8 %tmpvar182, 124
  br i1 %tmpcmp183, label %whileloop178, label %whilecont179

whileloop178:                                     ; preds = %whileloop178, %whilecont157
  %tmpvar184 = load i32, i32* %curNum, align 4
  %tmpvar185 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar184
  %tmpvar186 = load i32, i32* %index, align 4
  %tmpvar187 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar185, i32 0, i32 %tmpvar186
  %tmpvar188 = load i32, i32* %curIndex, align 4
  %tmpvar189 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar188
  %tmpvar190 = load i8, i8* %tmpvar187, align 1
  %tmpvar191 = load i8, i8* %tmpvar189, align 1
  store i8 %tmpvar191, i8* %tmpvar187, align 1
  %tmpvar192 = load i32, i32* %curIndex, align 4
  %tmpAdd193 = add i32 %tmpvar192, 1
  store volatile i32 %tmpAdd193, i32* %curIndex, align 4
  %tmpvar194 = load i32, i32* %index, align 4
  %tmpAdd195 = add i32 %tmpvar194, 1
  store volatile i32 %tmpAdd195, i32* %index, align 4
  %tmpvar196 = load i32, i32* %curIndex, align 4
  %tmpvar197 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar196
  %tmpvar198 = load i8, i8* %tmpvar197, align 1
  %tmpcmp199 = icmp ne i8 %tmpvar198, 124
  br i1 %tmpcmp199, label %whileloop178, label %whilecont179

whilecont179:                                     ; preds = %whileloop178, %whilecont157
  %tmpvar200 = load i32, i32* %curIndex, align 4
  %tmpAdd201 = add i32 %tmpvar200, 1
  store volatile i32 %tmpAdd201, i32* %curIndex, align 4
  %tmpvar205 = load i32, i32* %curIndex, align 4
  %tmpvar206 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar205
  %tmpvar207 = load i8, i8* %tmpvar206, align 1
  %tmpcmp208 = icmp ne i8 %tmpvar207, 0
  br i1 %tmpcmp208, label %then202, label %else203

then202:                                          ; preds = %whilecont179
  %tmpvar212 = load i32, i32* %curIndex, align 4
  %tmpvar213 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar212
  %tmpvar214 = load i8, i8* %tmpvar213, align 1
  %tmpcmp215 = icmp eq i8 %tmpvar214, 65
  br i1 %tmpcmp215, label %then209, label %else210

else203:                                          ; preds = %whilecont179
  %tmpvar259 = load i32, i32* %curNum, align 4
  %tmpvar260 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar259
  %tmpvar261 = load i32, i32* %tmpvar260, align 4
  store i32 -1, i32* %tmpvar260, align 4
  br label %merge204

merge204:                                         ; preds = %merge211, %else203
  %tmpvar262 = load i32, i32* %curNum, align 4
  %tmpAdd263 = add i32 %tmpvar262, 1
  store volatile i32 %tmpAdd263, i32* %curNum, align 4
  br label %merge

then209:                                          ; preds = %then202
  %tmpvar216 = load i32, i32* %curNum, align 4
  %tmpvar217 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar216
  %tmpvar218 = load i32, i32* %tmpvar217, align 4
  store i32 4, i32* %tmpvar217, align 4
  br label %merge211

else210:                                          ; preds = %then202
  %tmpvar222 = load i32, i32* %curIndex, align 4
  %tmpvar223 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar222
  %tmpvar224 = load i8, i8* %tmpvar223, align 1
  %tmpcmp225 = icmp eq i8 %tmpvar224, 66
  br i1 %tmpcmp225, label %then219, label %else220

merge211:                                         ; preds = %merge221, %then209
  br label %merge204

then219:                                          ; preds = %else210
  %tmpvar226 = load i32, i32* %curNum, align 4
  %tmpvar227 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar226
  %tmpvar228 = load i32, i32* %tmpvar227, align 4
  store i32 3, i32* %tmpvar227, align 4
  br label %merge221

else220:                                          ; preds = %else210
  %tmpvar232 = load i32, i32* %curIndex, align 4
  %tmpvar233 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar232
  %tmpvar234 = load i8, i8* %tmpvar233, align 1
  %tmpcmp235 = icmp eq i8 %tmpvar234, 67
  br i1 %tmpcmp235, label %then229, label %else230

merge221:                                         ; preds = %merge231, %then219
  br label %merge211

then229:                                          ; preds = %else220
  %tmpvar236 = load i32, i32* %curNum, align 4
  %tmpvar237 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar236
  %tmpvar238 = load i32, i32* %tmpvar237, align 4
  store i32 2, i32* %tmpvar237, align 4
  br label %merge231

else230:                                          ; preds = %else220
  %tmpvar242 = load i32, i32* %curIndex, align 4
  %tmpvar243 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar242
  %tmpvar244 = load i8, i8* %tmpvar243, align 1
  %tmpcmp245 = icmp eq i8 %tmpvar244, 68
  br i1 %tmpcmp245, label %then239, label %else240

merge231:                                         ; preds = %merge241, %then229
  br label %merge221

then239:                                          ; preds = %else230
  %tmpvar246 = load i32, i32* %curNum, align 4
  %tmpvar247 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar246
  %tmpvar248 = load i32, i32* %tmpvar247, align 4
  store i32 1, i32* %tmpvar247, align 4
  br label %merge241

else240:                                          ; preds = %else230
  %tmpvar252 = load i32, i32* %curIndex, align 4
  %tmpvar253 = getelementptr inbounds [500 x i8], [500 x i8]* %inputStr, i32 0, i32 %tmpvar252
  %tmpvar254 = load i8, i8* %tmpvar253, align 1
  %tmpcmp255 = icmp eq i8 %tmpvar254, 70
  br i1 %tmpcmp255, label %then249, label %else250

merge241:                                         ; preds = %merge251, %then239
  br label %merge231

then249:                                          ; preds = %else240
  %tmpvar256 = load i32, i32* %curNum, align 4
  %tmpvar257 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar256
  %tmpvar258 = load i32, i32* %tmpvar257, align 4
  store i32 0, i32* %tmpvar257, align 4
  br label %merge251

else250:                                          ; preds = %else240
  br label %merge251

merge251:                                         ; preds = %else250, %then249
  br label %merge241

forloop269:                                       ; preds = %foradd268, %whilecont
  %tmpvar273 = load i32, i32* %i, align 4
  %tmpvar274 = getelementptr inbounds [100 x i32], [100 x i32]* %credit, i32 0, i32 %tmpvar273
  %tmpvar275 = load i32, i32* %creditNum, align 4
  %tmpvar276 = load i32, i32* %tmpvar274, align 4
  store i32 %tmpvar276, i32* %creditNum, align 4
  %tmpvar277 = load float, float* %scoreNum, align 4
  store float 0.000000e+00, float* %scoreNum, align 4
  %tmpvar281 = load i32, i32* %i, align 4
  %tmpvar282 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar281
  %tmpvar283 = load i32, i32* %tmpvar282, align 4
  %tmpcmp284 = icmp eq i32 %tmpvar283, -1
  %tmpvar285 = load i32, i32* %i, align 4
  %tmpvar286 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar285
  %tmpvar287 = load i32, i32* %tmpvar286, align 4
  %tmpcmp288 = icmp eq i32 %tmpvar287, 0
  %tmpor = or i1 %tmpcmp284, %tmpcmp288
  br i1 %tmpor, label %then278, label %else279

foradd268:                                        ; preds = %merge280
  %tmpvar360 = load i32, i32* %i, align 4
  %tmpAdd361 = add i32 %tmpvar360, 1
  store volatile i32 %tmpAdd361, i32* %i, align 4
  %tmpvar362 = load i32, i32* %i, align 4
  %tmpvar363 = load i32, i32* %curNum, align 4
  %tmpcmp364 = icmp slt i32 %tmpvar362, %tmpvar363
  br i1 %tmpcmp364, label %forloop269, label %forcont267

forcont267:                                       ; preds = %foradd268, %whilecont
  %tmpvar368 = load i32, i32* %tryCredit, align 4
  %tmpcmp369 = icmp ne i32 %tmpvar368, 0
  br i1 %tmpcmp369, label %then365, label %else366

then278:                                          ; preds = %forloop269
  %tmpvar292 = load i32, i32* %i, align 4
  %tmpvar293 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar292
  %tmpvar294 = load i32, i32* %tmpvar293, align 4
  %tmpcmp295 = icmp eq i32 %tmpvar294, 0
  br i1 %tmpcmp295, label %then289, label %else290

else279:                                          ; preds = %forloop269
  %tmpvar311 = load i32, i32* %i, align 4
  %tmpvar312 = getelementptr inbounds [100 x i32], [100 x i32]* %score, i32 0, i32 %tmpvar311
  %tmpvar313 = load float, float* %scoreNum, align 4
  %tmpvar314 = load i32, i32* %tmpvar312, align 4
  %tmptypecast315 = sitofp i32 %tmpvar314 to float
  store float %tmptypecast315, float* %scoreNum, align 4
  %tmpvar316 = load i32, i32* %i, align 4
  %tmpvar317 = getelementptr inbounds [100 x i32], [100 x i32]* %credit, i32 0, i32 %tmpvar316
  %tmpvar318 = load i32, i32* %tryCredit, align 4
  %tmpvar319 = load i32, i32* %tmpvar317, align 4
  %tmpadd320 = add i32 %tmpvar318, %tmpvar319
  store i32 %tmpadd320, i32* %tryCredit, align 4
  %tmpvar321 = load i32, i32* %i, align 4
  %tmpvar322 = getelementptr inbounds [100 x i32], [100 x i32]* %credit, i32 0, i32 %tmpvar321
  %tmpvar323 = load i32, i32* %takenCredit, align 4
  %tmpvar324 = load i32, i32* %tmpvar322, align 4
  %tmpadd325 = add i32 %tmpvar323, %tmpvar324
  store i32 %tmpadd325, i32* %takenCredit, align 4
  %tmpvar326 = load i32, i32* %j, align 4
  store i32 0, i32* %j, align 4
  %tmpvar330 = load i32, i32* %i, align 4
  %tmpvar331 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar330
  %tmpvar332 = load i32, i32* %j, align 4
  %tmpvar333 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar331, i32 0, i32 %tmpvar332
  %tmpvar334 = load i8, i8* %tmpvar333, align 1
  %tmpcmp335 = icmp ne i8 %tmpvar334, 0
  br i1 %tmpcmp335, label %forloop329, label %forcont327

merge280:                                         ; preds = %forcont327, %merge291
  %tmpvar356 = load float, float* %scoreNum, align 4
  %tmpvar357 = load i32, i32* %creditNum, align 4
  %tmptypecast358 = sitofp i32 %tmpvar357 to float
  %tmpmulf = fmul float %tmpvar356, %tmptypecast358
  %tmpvar359 = load float, float* %gpa, align 4
  %tmpaddf = fadd float %tmpvar359, %tmpmulf
  store float %tmpaddf, float* %gpa, align 4
  br label %foradd268

then289:                                          ; preds = %then278
  %tmpvar296 = load i32, i32* %i, align 4
  %tmpvar297 = getelementptr inbounds [100 x i32], [100 x i32]* %credit, i32 0, i32 %tmpvar296
  %tmpvar298 = load i32, i32* %tryCredit, align 4
  %tmpvar299 = load i32, i32* %tmpvar297, align 4
  %tmpadd = add i32 %tmpvar298, %tmpvar299
  store i32 %tmpadd, i32* %tryCredit, align 4
  br label %merge291

else290:                                          ; preds = %then278
  br label %merge291

merge291:                                         ; preds = %else290, %then289
  %tmpvar300 = load i32, i32* %i, align 4
  %tmpvar301 = getelementptr inbounds [100 x i32], [100 x i32]* %credit, i32 0, i32 %tmpvar300
  %tmpvar302 = load i32, i32* %remainCredit, align 4
  %tmpvar303 = load i32, i32* %tmpvar301, align 4
  %tmpadd304 = add i32 %tmpvar302, %tmpvar303
  store i32 %tmpadd304, i32* %remainCredit, align 4
  %tmpvar305 = load i32, i32* %untakenIndex, align 4
  %tmpvar306 = getelementptr inbounds [100 x i32], [100 x i32]* %untakenCourseIndex, i32 0, i32 %tmpvar305
  %tmpvar307 = load i32, i32* %tmpvar306, align 4
  %tmpvar308 = load i32, i32* %i, align 4
  store i32 %tmpvar308, i32* %tmpvar306, align 4
  %tmpvar309 = load i32, i32* %untakenIndex, align 4
  %tmpAdd310 = add i32 %tmpvar309, 1
  store volatile i32 %tmpAdd310, i32* %untakenIndex, align 4
  br label %merge280

forloop329:                                       ; preds = %foradd328, %else279
  %tmpvar336 = load i32, i32* %takenIndex, align 4
  %tmpvar337 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %takenCourseName, i32 0, i32 %tmpvar336
  %tmpvar338 = load i32, i32* %j, align 4
  %tmpvar339 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar337, i32 0, i32 %tmpvar338
  %tmpvar340 = load i32, i32* %i, align 4
  %tmpvar341 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar340
  %tmpvar342 = load i32, i32* %j, align 4
  %tmpvar343 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar341, i32 0, i32 %tmpvar342
  %tmpvar344 = load i8, i8* %tmpvar339, align 1
  %tmpvar345 = load i8, i8* %tmpvar343, align 1
  store i8 %tmpvar345, i8* %tmpvar339, align 1
  br label %foradd328

foradd328:                                        ; preds = %forloop329
  %tmpvar346 = load i32, i32* %j, align 4
  %tmpAdd347 = add i32 %tmpvar346, 1
  store volatile i32 %tmpAdd347, i32* %j, align 4
  %tmpvar348 = load i32, i32* %i, align 4
  %tmpvar349 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar348
  %tmpvar350 = load i32, i32* %j, align 4
  %tmpvar351 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar349, i32 0, i32 %tmpvar350
  %tmpvar352 = load i8, i8* %tmpvar351, align 1
  %tmpcmp353 = icmp ne i8 %tmpvar352, 0
  br i1 %tmpcmp353, label %forloop329, label %forcont327

forcont327:                                       ; preds = %foradd328, %else279
  %tmpvar354 = load i32, i32* %takenIndex, align 4
  %tmpAdd355 = add i32 %tmpvar354, 1
  store volatile i32 %tmpAdd355, i32* %takenIndex, align 4
  br label %merge280

then365:                                          ; preds = %forcont267
  %tmpvar370 = load float, float* %gpa, align 4
  %tmpvar371 = load i32, i32* %tryCredit, align 4
  %tmptypecast372 = sitofp i32 %tmpvar371 to float
  %tmpdivf = fdiv float %tmpvar370, %tmptypecast372
  store float %tmpdivf, float* %gpa, align 4
  br label %merge367

else366:                                          ; preds = %forcont267
  br label %merge367

merge367:                                         ; preds = %else366, %then365
  %tmpvar373 = load float, float* %gpa, align 4
  %tmpdouble = fpext float %tmpvar373 to double
  %4 = call i8* @__decrypt(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @_Const_String_.2, i32 0, i32 0))
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @_Const_String_.2, i32 0, i32 0), double %tmpdouble)
  %5 = call i8* @__encrypt(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @_Const_String_.2, i32 0, i32 0))
  %tmpvar374 = load i32, i32* %tryCredit, align 4
  %6 = call i8* @__decrypt(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_.3, i32 0, i32 0))
  %printf375 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_.3, i32 0, i32 0), i32 %tmpvar374)
  %7 = call i8* @__encrypt(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_.3, i32 0, i32 0))
  %tmpvar376 = load i32, i32* %takenCredit, align 4
  %8 = call i8* @__decrypt(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_.4, i32 0, i32 0))
  %printf377 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_.4, i32 0, i32 0), i32 %tmpvar376)
  %9 = call i8* @__encrypt(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_.4, i32 0, i32 0))
  %tmpvar378 = load i32, i32* %remainCredit, align 4
  %10 = call i8* @__decrypt(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @_Const_String_.5, i32 0, i32 0))
  %printf379 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @_Const_String_.5, i32 0, i32 0), i32 %tmpvar378)
  %11 = call i8* @__encrypt(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @_Const_String_.5, i32 0, i32 0))
  %12 = call i8* @__decrypt(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @_Const_String_.6, i32 0, i32 0))
  %printf380 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @_Const_String_.6, i32 0, i32 0))
  %13 = call i8* @__encrypt(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @_Const_String_.6, i32 0, i32 0))
  %tmpvar384 = load i32, i32* %remainCredit, align 4
  %tmpcmp385 = icmp eq i32 %tmpvar384, 0
  br i1 %tmpcmp385, label %then381, label %else382

then381:                                          ; preds = %merge367
  %14 = call i8* @__decrypt(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @_Const_String_.7, i32 0, i32 0))
  %printf386 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @_Const_String_.7, i32 0, i32 0))
  %15 = call i8* @__encrypt(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @_Const_String_.7, i32 0, i32 0))
  ret i32 0

16:                                               ; No predecessors!
  br label %merge383

else382:                                          ; preds = %merge367
  br label %merge383

merge383:                                         ; preds = %else382, %16
  %tmpvar387 = load i32, i32* %i, align 4
  store i32 0, i32* %i, align 4
  %tmpvar391 = load i32, i32* %i, align 4
  %tmpvar392 = load i32, i32* %untakenIndex, align 4
  %tmpcmp393 = icmp slt i32 %tmpvar391, %tmpvar392
  br i1 %tmpcmp393, label %forloop390, label %forcont388

forloop390:                                       ; preds = %foradd389, %merge383
  %tmpvar394 = load i32, i32* %i, align 4
  %tmpvar395 = getelementptr inbounds [100 x i32], [100 x i32]* %untakenCourseIndex, i32 0, i32 %tmpvar394
  %tmpvar396 = load i32, i32* %j, align 4
  %tmpvar397 = load i32, i32* %tmpvar395, align 4
  store i32 %tmpvar397, i32* %j, align 4
  %tmpvar401 = load i32, i32* %j, align 4
  %tmpvar402 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar401
  %tmpvar403 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar402, i32 0, i32 0
  %tmpvar404 = load i8, i8* %tmpvar403, align 1
  %tmpcmp405 = icmp eq i8 %tmpvar404, 0
  br i1 %tmpcmp405, label %then398, label %else399

foradd389:                                        ; preds = %merge400
  %tmpvar605 = load i32, i32* %i, align 4
  %tmpAdd606 = add i32 %tmpvar605, 1
  store volatile i32 %tmpAdd606, i32* %i, align 4
  %tmpvar607 = load i32, i32* %i, align 4
  %tmpvar608 = load i32, i32* %untakenIndex, align 4
  %tmpcmp609 = icmp slt i32 %tmpvar607, %tmpvar608
  br i1 %tmpcmp609, label %forloop390, label %forcont388

forcont388:                                       ; preds = %foradd389, %merge383
  ret i32 0

then398:                                          ; preds = %forloop390
  %17 = call i8* @__decrypt(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.8, i32 0, i32 0))
  %printf406 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.8, i32 0, i32 0), i32 32, i32 32)
  %18 = call i8* @__encrypt(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.8, i32 0, i32 0))
  %tmpvar407 = load i32, i32* %k, align 4
  store i32 0, i32* %k, align 4
  %tmpvar411 = load i32, i32* %j, align 4
  %tmpvar412 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar411
  %tmpvar413 = load i32, i32* %k, align 4
  %tmpvar414 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar412, i32 0, i32 %tmpvar413
  %tmpvar415 = load i8, i8* %tmpvar414, align 1
  %tmpcmp416 = icmp ne i8 %tmpvar415, 0
  br i1 %tmpcmp416, label %forloop410, label %forcont408

else399:                                          ; preds = %forloop390
  %tmpvar432 = load i32, i32* %ii, align 4
  store i32 0, i32* %ii, align 4
  %tmpvar436 = load i32, i32* %ii, align 4
  %tmpcmp437 = icmp slt i32 %tmpvar436, 100
  br i1 %tmpcmp437, label %forloop435, label %forcont433

merge400:                                         ; preds = %merge576, %forcont408
  br label %foradd389

forloop410:                                       ; preds = %foradd409, %then398
  %tmpvar417 = load i32, i32* %j, align 4
  %tmpvar418 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar417
  %tmpvar419 = load i32, i32* %k, align 4
  %tmpvar420 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar418, i32 0, i32 %tmpvar419
  %tmpvar421 = load i8, i8* %tmpvar420, align 1
  %19 = call i8* @__decrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.9, i32 0, i32 0))
  %printf422 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.9, i32 0, i32 0), i8 %tmpvar421)
  %20 = call i8* @__encrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.9, i32 0, i32 0))
  br label %foradd409

foradd409:                                        ; preds = %forloop410
  %tmpvar423 = load i32, i32* %k, align 4
  %tmpAdd424 = add i32 %tmpvar423, 1
  store volatile i32 %tmpAdd424, i32* %k, align 4
  %tmpvar425 = load i32, i32* %j, align 4
  %tmpvar426 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar425
  %tmpvar427 = load i32, i32* %k, align 4
  %tmpvar428 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar426, i32 0, i32 %tmpvar427
  %tmpvar429 = load i8, i8* %tmpvar428, align 1
  %tmpcmp430 = icmp ne i8 %tmpvar429, 0
  br i1 %tmpcmp430, label %forloop410, label %forcont408

forcont408:                                       ; preds = %foradd409, %then398
  %21 = call i8* @__decrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.10, i32 0, i32 0))
  %printf431 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.10, i32 0, i32 0), i32 10)
  %22 = call i8* @__encrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.10, i32 0, i32 0))
  br label %merge400

forloop435:                                       ; preds = %foradd434, %else399
  %tmpvar438 = load i32, i32* %ii, align 4
  %tmpvar439 = getelementptr inbounds [100 x i32], [100 x i32]* %preCourseTrue, i32 0, i32 %tmpvar438
  %tmpvar440 = load i32, i32* %tmpvar439, align 4
  store i32 0, i32* %tmpvar439, align 4
  %tmpvar441 = load i32, i32* %ii, align 4
  %tmpvar442 = getelementptr inbounds [100 x i8], [100 x i8]* %token, i32 0, i32 %tmpvar441
  %tmpvar443 = load i8, i8* %tmpvar442, align 1
  store i8 0, i8* %tmpvar442, align 1
  br label %foradd434

foradd434:                                        ; preds = %forloop435
  %tmpvar444 = load i32, i32* %ii, align 4
  %tmpAdd445 = add i32 %tmpvar444, 1
  store volatile i32 %tmpAdd445, i32* %ii, align 4
  %tmpvar446 = load i32, i32* %ii, align 4
  %tmpcmp447 = icmp slt i32 %tmpvar446, 100
  br i1 %tmpcmp447, label %forloop435, label %forcont433

forcont433:                                       ; preds = %foradd434, %else399
  %tmpvar448 = load i32, i32* %trueIndex, align 4
  store i32 0, i32* %trueIndex, align 4
  %tmpvar449 = load i32, i32* %tokenIndex, align 4
  store i32 0, i32* %tokenIndex, align 4
  %tmpvar450 = load i32, i32* %k, align 4
  store i32 0, i32* %k, align 4
  %tmpvar454 = load i32, i32* %j, align 4
  %tmpvar455 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar454
  %tmpvar456 = load i32, i32* %k, align 4
  %tmpvar457 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar455, i32 0, i32 %tmpvar456
  %tmpvar458 = load i8, i8* %tmpvar457, align 1
  %tmpcmp459 = icmp ne i8 %tmpvar458, 0
  br i1 %tmpcmp459, label %forloop453, label %forcont451

forloop453:                                       ; preds = %foradd452, %forcont433
  %tmpvar460 = load i32, i32* %iii, align 4
  store i32 0, i32* %iii, align 4
  %tmpvar464 = load i32, i32* %iii, align 4
  %tmpcmp465 = icmp slt i32 %tmpvar464, 5
  br i1 %tmpcmp465, label %forloop463, label %forcont461

foradd452:                                        ; preds = %merge548
  %tmpvar560 = load i32, i32* %k, align 4
  %tmpAdd561 = add i32 %tmpvar560, 1
  store volatile i32 %tmpAdd561, i32* %k, align 4
  %tmpvar562 = load i32, i32* %j, align 4
  %tmpvar563 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar562
  %tmpvar564 = load i32, i32* %k, align 4
  %tmpvar565 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar563, i32 0, i32 %tmpvar564
  %tmpvar566 = load i8, i8* %tmpvar565, align 1
  %tmpcmp567 = icmp ne i8 %tmpvar566, 0
  br i1 %tmpcmp567, label %forloop453, label %forcont451

forcont451:                                       ; preds = %foradd452, %forcont433
  %tmpvar568 = load i32, i32* %j, align 4
  %tmpvar569 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar568
  %tmpvar570 = load i32, i32* %tokenIndex, align 4
  %tmpvar571 = load i32, i32* %trueIndex, align 4
  %tmpcall572 = call i32 @boolExpression([100 x i8]* %tmpvar569, [100 x i8]* %token, i32 0, i32 %tmpvar570, [100 x i32]* %preCourseTrue, i32 0, i32 %tmpvar571)
  %tmpvar573 = load i32, i32* %result, align 4
  store i32 %tmpcall572, i32* %result, align 4
  %tmpvar577 = load i32, i32* %result, align 4
  %tmpcmp578 = icmp sgt i32 %tmpvar577, 0
  br i1 %tmpcmp578, label %then574, label %else575

forloop463:                                       ; preds = %foradd462, %forloop453
  %tmpvar466 = load i32, i32* %iii, align 4
  %tmpvar467 = getelementptr inbounds [100 x i8], [100 x i8]* %tempName, i32 0, i32 %tmpvar466
  %tmpvar468 = load i8, i8* %tmpvar467, align 1
  store i8 0, i8* %tmpvar467, align 1
  br label %foradd462

foradd462:                                        ; preds = %forloop463
  %tmpvar469 = load i32, i32* %iii, align 4
  %tmpAdd470 = add i32 %tmpvar469, 1
  store volatile i32 %tmpAdd470, i32* %iii, align 4
  %tmpvar471 = load i32, i32* %iii, align 4
  %tmpcmp472 = icmp slt i32 %tmpvar471, 5
  br i1 %tmpcmp472, label %forloop463, label %forcont461

forcont461:                                       ; preds = %foradd462, %forloop453
  %tmpvar473 = load i32, i32* %tempIndex, align 4
  store i32 0, i32* %tempIndex, align 4
  %tmpvar476 = load i32, i32* %j, align 4
  %tmpvar477 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar476
  %tmpvar478 = load i32, i32* %k, align 4
  %tmpvar479 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar477, i32 0, i32 %tmpvar478
  %tmpvar480 = load i8, i8* %tmpvar479, align 1
  %tmpcmp481 = icmp ne i8 %tmpvar480, 44
  %tmpvar482 = load i32, i32* %j, align 4
  %tmpvar483 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar482
  %tmpvar484 = load i32, i32* %k, align 4
  %tmpvar485 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar483, i32 0, i32 %tmpvar484
  %tmpvar486 = load i8, i8* %tmpvar485, align 1
  %tmpcmp487 = icmp ne i8 %tmpvar486, 59
  %tmpand = and i1 %tmpcmp481, %tmpcmp487
  %tmpvar488 = load i32, i32* %j, align 4
  %tmpvar489 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar488
  %tmpvar490 = load i32, i32* %k, align 4
  %tmpvar491 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar489, i32 0, i32 %tmpvar490
  %tmpvar492 = load i8, i8* %tmpvar491, align 1
  %tmpcmp493 = icmp ne i8 %tmpvar492, 0
  %tmpand494 = and i1 %tmpand, %tmpcmp493
  br i1 %tmpand494, label %whileloop474, label %whilecont475

whileloop474:                                     ; preds = %whileloop474, %forcont461
  %tmpvar495 = load i32, i32* %tempIndex, align 4
  %tmpvar496 = getelementptr inbounds [100 x i8], [100 x i8]* %tempName, i32 0, i32 %tmpvar495
  %tmpvar497 = load i32, i32* %j, align 4
  %tmpvar498 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar497
  %tmpvar499 = load i32, i32* %k, align 4
  %tmpvar500 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar498, i32 0, i32 %tmpvar499
  %tmpvar501 = load i8, i8* %tmpvar496, align 1
  %tmpvar502 = load i8, i8* %tmpvar500, align 1
  store i8 %tmpvar502, i8* %tmpvar496, align 1
  %tmpvar503 = load i32, i32* %tempIndex, align 4
  %tmpAdd504 = add i32 %tmpvar503, 1
  store volatile i32 %tmpAdd504, i32* %tempIndex, align 4
  %tmpvar505 = load i32, i32* %k, align 4
  %tmpAdd506 = add i32 %tmpvar505, 1
  store volatile i32 %tmpAdd506, i32* %k, align 4
  %tmpvar507 = load i32, i32* %j, align 4
  %tmpvar508 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar507
  %tmpvar509 = load i32, i32* %k, align 4
  %tmpvar510 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar508, i32 0, i32 %tmpvar509
  %tmpvar511 = load i8, i8* %tmpvar510, align 1
  %tmpcmp512 = icmp ne i8 %tmpvar511, 44
  %tmpvar513 = load i32, i32* %j, align 4
  %tmpvar514 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar513
  %tmpvar515 = load i32, i32* %k, align 4
  %tmpvar516 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar514, i32 0, i32 %tmpvar515
  %tmpvar517 = load i8, i8* %tmpvar516, align 1
  %tmpcmp518 = icmp ne i8 %tmpvar517, 59
  %tmpand519 = and i1 %tmpcmp512, %tmpcmp518
  %tmpvar520 = load i32, i32* %j, align 4
  %tmpvar521 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar520
  %tmpvar522 = load i32, i32* %k, align 4
  %tmpvar523 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar521, i32 0, i32 %tmpvar522
  %tmpvar524 = load i8, i8* %tmpvar523, align 1
  %tmpcmp525 = icmp ne i8 %tmpvar524, 0
  %tmpand526 = and i1 %tmpand519, %tmpcmp525
  br i1 %tmpand526, label %whileloop474, label %whilecont475

whilecont475:                                     ; preds = %whileloop474, %forcont461
  %tmpvar530 = load i32, i32* %j, align 4
  %tmpvar531 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar530
  %tmpvar532 = load i32, i32* %k, align 4
  %tmpvar533 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar531, i32 0, i32 %tmpvar532
  %tmpvar534 = load i8, i8* %tmpvar533, align 1
  %tmpcmp535 = icmp ne i8 %tmpvar534, 0
  br i1 %tmpcmp535, label %then527, label %else528

then527:                                          ; preds = %whilecont475
  %tmpvar536 = load i32, i32* %tokenIndex, align 4
  %tmpvar537 = getelementptr inbounds [100 x i8], [100 x i8]* %token, i32 0, i32 %tmpvar536
  %tmpvar538 = load i32, i32* %j, align 4
  %tmpvar539 = getelementptr inbounds [100 x [200 x i8]], [100 x [200 x i8]]* @preCourse, i32 0, i32 %tmpvar538
  %tmpvar540 = load i32, i32* %k, align 4
  %tmpvar541 = getelementptr inbounds [200 x i8], [200 x i8]* %tmpvar539, i32 0, i32 %tmpvar540
  %tmpvar542 = load i8, i8* %tmpvar537, align 1
  %tmpvar543 = load i8, i8* %tmpvar541, align 1
  store i8 %tmpvar543, i8* %tmpvar537, align 1
  %tmpvar544 = load i32, i32* %tokenIndex, align 4
  %tmpAdd545 = add i32 %tmpvar544, 1
  store volatile i32 %tmpAdd545, i32* %tokenIndex, align 4
  br label %merge529

else528:                                          ; preds = %whilecont475
  br label %merge529

merge529:                                         ; preds = %else528, %then527
  %tmpvar549 = load i32, i32* %tempIndex, align 4
  %tmpvar550 = load i32, i32* %takenIndex, align 4
  %tmpcall = call i32 @myStrcmp([100 x i8]* %tempName, i32 %tmpvar549, [100 x [100 x i8]]* %takenCourseName, i32 %tmpvar550)
  %tmpcmp551 = icmp sgt i32 %tmpcall, 0
  br i1 %tmpcmp551, label %then546, label %else547

then546:                                          ; preds = %merge529
  %tmpvar552 = load i32, i32* %trueIndex, align 4
  %tmpvar553 = getelementptr inbounds [100 x i32], [100 x i32]* %preCourseTrue, i32 0, i32 %tmpvar552
  %tmpvar554 = load i32, i32* %tmpvar553, align 4
  store i32 1, i32* %tmpvar553, align 4
  br label %merge548

else547:                                          ; preds = %merge529
  %tmpvar555 = load i32, i32* %trueIndex, align 4
  %tmpvar556 = getelementptr inbounds [100 x i32], [100 x i32]* %preCourseTrue, i32 0, i32 %tmpvar555
  %tmpvar557 = load i32, i32* %tmpvar556, align 4
  store i32 0, i32* %tmpvar556, align 4
  br label %merge548

merge548:                                         ; preds = %else547, %then546
  %tmpvar558 = load i32, i32* %trueIndex, align 4
  %tmpAdd559 = add i32 %tmpvar558, 1
  store volatile i32 %tmpAdd559, i32* %trueIndex, align 4
  br label %foradd452

then574:                                          ; preds = %forcont451
  %23 = call i8* @__decrypt(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.11, i32 0, i32 0))
  %printf579 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.11, i32 0, i32 0), i32 32, i32 32)
  %24 = call i8* @__encrypt(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.11, i32 0, i32 0))
  %tmpvar580 = load i32, i32* %k, align 4
  store i32 0, i32* %k, align 4
  %tmpvar584 = load i32, i32* %j, align 4
  %tmpvar585 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar584
  %tmpvar586 = load i32, i32* %k, align 4
  %tmpvar587 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar585, i32 0, i32 %tmpvar586
  %tmpvar588 = load i8, i8* %tmpvar587, align 1
  %tmpcmp589 = icmp ne i8 %tmpvar588, 0
  br i1 %tmpcmp589, label %forloop583, label %forcont581

else575:                                          ; preds = %forcont451
  br label %merge576

merge576:                                         ; preds = %forcont581, %else575
  br label %merge400

forloop583:                                       ; preds = %foradd582, %then574
  %tmpvar590 = load i32, i32* %j, align 4
  %tmpvar591 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar590
  %tmpvar592 = load i32, i32* %k, align 4
  %tmpvar593 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar591, i32 0, i32 %tmpvar592
  %tmpvar594 = load i8, i8* %tmpvar593, align 1
  %25 = call i8* @__decrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.12, i32 0, i32 0))
  %printf595 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.12, i32 0, i32 0), i8 %tmpvar594)
  %26 = call i8* @__encrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.12, i32 0, i32 0))
  br label %foradd582

foradd582:                                        ; preds = %forloop583
  %tmpvar596 = load i32, i32* %k, align 4
  %tmpAdd597 = add i32 %tmpvar596, 1
  store volatile i32 %tmpAdd597, i32* %k, align 4
  %tmpvar598 = load i32, i32* %j, align 4
  %tmpvar599 = getelementptr inbounds [100 x [100 x i8]], [100 x [100 x i8]]* %courseName, i32 0, i32 %tmpvar598
  %tmpvar600 = load i32, i32* %k, align 4
  %tmpvar601 = getelementptr inbounds [100 x i8], [100 x i8]* %tmpvar599, i32 0, i32 %tmpvar600
  %tmpvar602 = load i8, i8* %tmpvar601, align 1
  %tmpcmp603 = icmp ne i8 %tmpvar602, 0
  br i1 %tmpcmp603, label %forloop583, label %forcont581

forcont581:                                       ; preds = %foradd582, %then574
  %27 = call i8* @__decrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.13, i32 0, i32 0))
  %printf604 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.13, i32 0, i32 0), i32 10)
  %28 = call i8* @__encrypt(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.13, i32 0, i32 0))
  br label %merge576
}

declare i8* @__decrypt(i8*)

declare i8* @__encrypt(i8*)
