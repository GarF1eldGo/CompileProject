#include "code_gen.h"

// #include "llvm/ADT/APFloat.h"
// #include "llvm/ADT/Optional.h"
// #include "llvm/ADT/STLExtras.h"
// #include "llvm/IR/BasicBlock.h"
// #include "llvm/IR/Constants.h"
// #include "llvm/IR/DerivedTypes.h"
// #include "llvm/IR/Function.h"
// #include "llvm/IR/Instructions.h"
// #include "llvm/IR/IRBuilder.h"
// #include "llvm/IR/LLVMContext.h"
// #include "llvm/IR/LegacyPassManager.h"
// #include "llvm/IR/Module.h"
// #include "llvm/IR/Type.h"
// #include "llvm/IR/Verifier.h"
// #include "llvm/IR/AssemblyAnnotationWriter.h"
// #include "llvm/Support/FileSystem.h"
// #include "llvm/Support/Host.h"
// #include "llvm/Support/raw_ostream.h"
// #include "llvm/Support/TargetRegistry.h"
// #include "llvm/Support/raw_os_ostream.h"
// #include "llvm/Support/TargetSelect.h"
// #include "llvm/Target/TargetMachine.h"
// #include "llvm/Target/TargetOptions.h"

CodeGen *generator;

void CodeGen::generate(translation_unit* root) {

}

CodeGen::CodeGen(/* args */) {

}

CodeGen::~CodeGen() {

}
llvm::Value* IRError(string msg){
    cout<<msg<<endl;
    return nullptr;
}


llvm::Value* translation_unit::CodeGen(){

}


llvm::Value* unary_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"unary_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("unary_expression error in leaf node: postfix_expression");
            }
            else{
                return tmp;
            }
        case 2:
            llvm::Value* tmp = this->children[1]->CodeGen();
            if(tmp == nullptr){
                return IRError("unary_expression error in leaf node: unary_expression");
            }
            else if(tmp->getType() == llvm::Type::getInt1Ty(context)){
                this->type = TYPEINT;
                return builder.CreateAdd(tmp, builder.getInt32(1), "tmpAdd");
            }
            else if(tmp->getType() == llvm::Type::getFloatTy(context)){
                this->type = TYPEFLOAT;
                return builder.CreateFAdd(tmp, llvm::ConstantFP::get(builder.getFloatTy(), llvm::APFloat((float)1)), "tmpAddf");
            }
            else{
                return IRError("bool/char type could not associate with '++' operator");
            }
        case 3:
            llvm::Value* tmp = this->children[1]->CodeGen();
            if(tmp == nullptr){
                return IRError("unary_expression error in leaf node: unary_expression");
            }
            else if(tmp->getType() == llvm::Type::getInt1Ty(context)){
                return builder.CreateSub(tmp, builder.getInt32(1), "tmpSub");
            }
            else if(tmp->getType() == llvm::Type::getFloatTy(context)){
                return builder.CreateFSub(tmp, llvm::ConstantFP::get(builder.getFloatTy(), llvm::APFloat((float)1)), "tmpSubf");
            }
            else{
                return IRError("bool/char type could not associate with '--' operator");
            }
        case 4:
            llvm::Value* tmp = this->children[1]->CodeGen();
            if(tmp == nullptr){
                return IRError("unary_expression error in leaf node: cast_expression");
            }
            else if(tmp->getType() == llvm::Type::getInt8Ty(context)){
                return IRError("char type could not associate with unary_operator");
            }
            else{
                llvm::Value* rs = this->children[0]->CodeGen();
                if((dynamic_cast<operatorAST*>(this->children[0]))->op.compare("-") == 0){
                    if(tmp->getType() == llvm::Type::getInt32Ty(context)){
                        return builder.CreateNeg(tmp, "tmpNeg");
                    }
                    else if(tmp->getType() == llvm::Type::getFloatTy(context)){
                        return builder.CreateFNeg(tmp, "tmpNegf");
                    }
                    else{
                        return IRError("bool type could not associate with '-' operator");
                    }
                }
                else if((dynamic_cast<operatorAST*>(this->children[0]))->op.compare("!") == 0){
                    if(tmp->getType() == llvm::Type::getInt1Ty(context)){
                        return builder.CreateNot(tmp, "tmpNot");
                    }
                    else{
                        return IRError("int/float type could not associate with '~' operator");
                    }
                }
                else if((dynamic_cast<operatorAST*>(this->children[0]))->op.compare("-") == 0){
                    if(tmp->getType() == llvm::Type::getInt1Ty(context)){
                        return builder.CreateNot(tmp, "tmpNot");
                    }
                    else{
                        return IRError("int/float type could not associate with '~' operator");
                    }
                }
                else{
                    return IRError("unary_expression error: illegal operator");
                }
            }
        case 5:
            llvm::Value* tmp = this->children[1]->CodeGen();
            if(tmp == nullptr){
                return IRError("unary_expression error in leaf node: unary_expression");
            }
            else if(tmp->getType() == llvm::Type::getInt1Ty(context)){
                return builder.getInt32(1);
            }
            else if(tmp->getType() == llvm::Type::getInt32Ty(context)){
                return builder.getInt32(4);
            }
            else if(tmp->getType() == llvm::Type::getFloatTy(context)){
                return builder.getInt32(4);
            }
            else if(tmp->getType() == llvm::Type::getInt8Ty(context)){
                return builder.getInt32(1);
            }
            else {
                return IRError("unary_expression type error with leaf node: unary_expression");
            }
        case 6:
            llvm::Value* tmp = this->children[1]->CodeGen();
            if(tmp == nullptr){
                return IRError("unary_expression error in leaf node: type_name");
            }
            else if(dynamic_cast<typeAST*> ((dynamic_cast<type_name *>(this->children[2])->children)[0])->type == 8){
                return builder.getInt32(1);
            }
            else if(dynamic_cast<typeAST*> ((dynamic_cast<type_name *>(this->children[2])->children)[0])->type == 4){
                return builder.getInt32(4);
            }
            else if(dynamic_cast<typeAST*> ((dynamic_cast<type_name *>(this->children[2])->children)[0])->type == 6){
                return builder.getInt32(4);
            }
            else if(dynamic_cast<typeAST*> ((dynamic_cast<type_name *>(this->children[2])->children)[0])->type == 2){
                return builder.getInt32(1);
            }
            else {
                return IRError("unary_expression type error with leaf node: type_name");
            }

    }
    return nullptr;
}


llvm::Value* unary_operator::CodeGen(){
    #ifdef DEBUG
        cout<<"unary_operator type:"<<this->type<<endl;
    #endif
    // switch(this->type){
    //     case 4:
    //         if(cast_expression->getType() == llvm::Type::getInt32Ty(context)){
    //             return builder.CreateNeg(cast_expression, "tmpNeg");
    //         }
    //         else if(cast_expression->getType() == llvm::Type::getFloatTy(context)){
    //             return builder.CreateFNeg(cast_expression, "tmpNegf");
    //         }
    //         else{
    //             return IRError("bool type could not associate with '-' operator");
    //         }
    //     case 5:
    //         if(cast_expression->getType() == llvm::Type::getInt1Ty(context)){
    //             return builder.CreateNot(cast_expression, "tmpNot");
    //         }
    //         else{
    //             return IRError("int/float type could not associate with '~' operator");
    //         }
    //     case 6:
    //         if(cast_expression->getType() == llvm::Type::getInt1Ty(context)){
    //             return builder.CreateNot(cast_expression, "tmpNot");
    //         }
    //         else{
    //             return IRError("int/float type could not associate with '!' operator");
    //         }
    // }
    return nullptr;
}

llvm::Instruction::CastOps getCastInst(llvm::Type* src, llvm::Type* dst) {
    if (src == llvm::Type::getFloatTy(context) && dst == llvm::Type::getInt32Ty(context)) {
        return llvm::Instruction::FPToSI;
    }
    else if (src == llvm::Type::getInt32Ty(context) && dst == llvm::Type::getFloatTy(context)) {
        return llvm::Instruction::SIToFP;
    }
    else if (src == llvm::Type::getInt8Ty(context) && dst == llvm::Type::getFloatTy(context)) {
        return llvm::Instruction::UIToFP;
    }
    else if (src == llvm::Type::getInt8Ty(context) && dst == llvm::Type::getInt32Ty(context)) {
        return llvm::Instruction::ZExt;
    }
    else if (src == llvm::Type::getInt32Ty(context) && dst == llvm::Type::getInt8Ty(context)) {
        return llvm::Instruction::Trunc;
    }
    else {
        IRError("cast_expression error: two types are contradict");
    }
}


llvm::Value* typeCast(llvm::Value* src, llvm::Type* dst) {
    if(src->getType() == dst){
        return src;
    }
    else{
        llvm::Instruction::CastOps op = getCastInst(src->getType(), dst);
        return builder.CreateCast(op, src, dst, "tmptypecast");
    }
}


llvm::Value* cast_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"cast_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("cast_expression error in leaf node: unary_expression");
            }
            else{
                return tmp;
            }
        case 2:
            llvm::Value* tmp1 = this->children[1]->CodeGen();
            llvm::Value* tmp2 = this->children[3]->CodeGen();
            // llvm::Value* rs = nullptr;
            if(tmp1==nullptr||tmp2==nullptr){
                return IRError("cast_expression error in leaf node: type_name or cast_expression");
            }
            else if(dynamic_cast<typeAST*> ((dynamic_cast<type_name *>(this->children[1])->children)[0])->type == 2){
                return typeCast(tmp2, llvm::Type::getInt8Ty(context));
            }
            else if(dynamic_cast<typeAST*> ((dynamic_cast<type_name *>(this->children[1])->children)[0])->type == 4){
                return typeCast(tmp2, llvm::Type::getInt32Ty(context));
            }
            else if(dynamic_cast<typeAST*> ((dynamic_cast<type_name *>(this->children[1])->children)[0])->type == 6){
                return typeCast(tmp2, llvm::Type::getFloatTy(context));
            }
    }
    return nullptr;
}

llvm::Value* multiplicative_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"multiplicative_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("multiplicative_expression error in leaf node: cast_expression");
            }
            else{
                return tmp;
            }
        case 2:
            llvm::Value* tmp1 = this->children[0]->CodeGen();
            llvm::Value* tmp2 = this->children[2]->CodeGen();
            // llvm::Value* rs = nullptr;
            if(tmp1==nullptr||tmp2==nullptr){
                return IRError("multiplicative_expression in leaf node: multiplicative_expression or cast_expression");
            }
            else if(tmp1->getType() == llvm::Type::getInt1Ty(context)||tmp2->getType() == llvm::Type::getInt1Ty(context)){
                return IRError("multiplicative_expression error: bool type could not associate with '*' operator");
            }
            else if(tmp1->getType() == llvm::Type::getInt8Ty(context)||tmp2->getType() == llvm::Type::getInt8Ty(context)){
                return IRError("multiplicative_expression error: char type could not associate with '*' operator");
            }
            else{
                 if(tmp1->getType() == llvm::Type::getFloatTy(context)||tmp2->getType() == llvm::Type::getFloatTy(context)){
                     tmp1 = typeCast(tmp1, llvm::Type::getFloatTy(context));
                     tmp2 = typeCast(tmp2, llvm::Type::getFloatTy(context));
                     return builder.CreateFMul(tmp1, tmp2, "tmpmulf");
                 }
                 else{
                     return builder.CreateMul(tmp1, tmp2, "tmpmul");
                 }
            }
        case 3:
            llvm::Value* tmp1 = this->children[0]->CodeGen();
            llvm::Value* tmp2 = this->children[2]->CodeGen();
            // llvm::Value* rs = nullptr;
            if(tmp1==nullptr||tmp2==nullptr){
                return IRError("multiplicative_expression error in leaf node: multiplicative_expression or cast_expression");
            }
            else if(tmp1->getType() == llvm::Type::getInt1Ty(context)||tmp2->getType() == llvm::Type::getInt1Ty(context)){
                return IRError("multiplicative_expression error: bool type could not associate with '*' operator");
            }
            else if(tmp1->getType() == llvm::Type::getInt8Ty(context)||tmp2->getType() == llvm::Type::getInt8Ty(context)){
                return IRError("multiplicative_expression error: char type could not associate with '*' operator");
            }
            else{
                tmp1 = typeCast(tmp1, llvm::Type::getFloatTy(context));
                tmp2 = typeCast(tmp2, llvm::Type::getFloatTy(context));
                return builder.CreateFDiv(tmp1, tmp2, "tmpmulf");
            }
        case 4:
            // '%' operator is not finished.
    }
    return nullptr;
}
llvm::Value* additive_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"additive_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("additive_expression error in leaf node: multiplicative_expression");
            }
            else{
                return tmp;
            }
        case 2:
            llvm::Value* tmp1 = this->children[0]->CodeGen();
            llvm::Value* tmp2 = this->children[2]->CodeGen();
            // llvm::Value* rs = nullptr;
            if(tmp1==nullptr||tmp2==nullptr){
                return IRError("additive_expression error in leaf node: additive_expression or multiplicative_expression");
            }
            else if(tmp1->getType() == llvm::Type::getInt1Ty(context)||tmp2->getType() == llvm::Type::getInt1Ty(context)){
                return IRError("additive_expression error: bool type could not associate with '+' operator");
            }
            else if(tmp1->getType() == llvm::Type::getInt8Ty(context)||tmp2->getType() == llvm::Type::getInt8Ty(context)){
                if(tmp1->getType() == llvm::Type::getFloatTy(context)||tmp2->getType() == llvm::Type::getFloatTy(context)){
                    return IRError("additive_expression error: char type could not connected with float type by '+' operator");
                }
                else{
                    tmp1 = typeCast(tmp1, llvm::Type::getInt32Ty(context));
                    tmp2 = typeCast(tmp2, llvm::Type::getInt32Ty(context));
                    return builder.CreateFAdd(tmp1, tmp2, "tmpaddf");
                }
                
            }
            else{
                 if(tmp1->getType() == llvm::Type::getFloatTy(context)||tmp2->getType() == llvm::Type::getFloatTy(context)){
                     tmp1 = typeCast(tmp1, llvm::Type::getFloatTy(context));
                     tmp2 = typeCast(tmp2, llvm::Type::getFloatTy(context));
                     return builder.CreateFAdd(tmp1, tmp2, "tmpaddf");
                 }
                 else{
                     return builder.CreateAdd(tmp1, tmp2, "tmpadd");
                 }
            }
        case 3:
            llvm::Value* tmp1 = this->children[0]->CodeGen();
            llvm::Value* tmp2 = this->children[2]->CodeGen();
            // llvm::Value* rs = nullptr;
            if(tmp1==nullptr||tmp2==nullptr){
                return IRError("additive_expression error in leaf node: additive_expression or multiplicative_expression");
            }
            else if(tmp1->getType() == llvm::Type::getInt1Ty(context)||tmp2->getType() == llvm::Type::getInt1Ty(context)){
                return IRError("additive_expression error: bool type could not associate with '+' operator");
            }
            else if(tmp1->getType() == llvm::Type::getInt8Ty(context)||tmp2->getType() == llvm::Type::getInt8Ty(context)){
                if(tmp1->getType() == llvm::Type::getFloatTy(context)||tmp2->getType() == llvm::Type::getFloatTy(context)){
                    return IRError("additive_expression error: char type could not connected with float type by '+' operator");
                }
                else{
                    tmp1 = typeCast(tmp1, llvm::Type::getInt32Ty(context));
                    tmp2 = typeCast(tmp2, llvm::Type::getInt32Ty(context));
                    return builder.CreateFSub(tmp1, tmp2, "tmpsubf");
                }
                
            }
            else{
                if(tmp1->getType() == llvm::Type::getFloatTy(context)||tmp2->getType() == llvm::Type::getFloatTy(context)){
                     tmp1 = typeCast(tmp1, llvm::Type::getFloatTy(context));
                     tmp2 = typeCast(tmp2, llvm::Type::getFloatTy(context));
                     return builder.CreateFSub(tmp1, tmp2, "tmpsubf");
                 }
                 else{
                     return builder.CreateSub(tmp1, tmp2, "tmpsub");
                 }
            }
    }
    return nullptr;
}

llvm::Value* shift_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"shift_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("shift_expression error in leaf node: additive_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;
}

llvm::Value* relational_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;
}

llvm::Value* equality_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* and_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* exclusive_or_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* inclusive_or_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* logical_and_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* logical_or_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* conditional_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* assignment_expression::CodeGen(){
    #ifdef DEBUG
        cout<<"relational_expression type:"<<this->type<<endl;
    #endif
    switch(this->type){
        case 1:
            llvm::Value* tmp = this->children[0]->CodeGen();
            if(tmp == nullptr){
                return IRError("relational_expression error in leaf node: shift_expression");
            }
            else{
                return tmp;
            }
    }
    return nullptr;

}

llvm::Value* assignment_operator::CodeGen(){

}