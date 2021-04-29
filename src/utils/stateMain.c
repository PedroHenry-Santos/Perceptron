/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Handle the states of the main application block.
* Language: C.
*/

/*
* Starts the state of the main application block.
*
* This function returns nothing.
*/
void startState (TStateMain *__state);
/*
* Updates the state of the main application block.
*
* This function returns nothing.
*/
void checkState (TStateMain *__state);
/*
* Updates the section based on the new state.
*
* This function returns nothing.
*/
void updateSection (TSection *__state);

void startState (TStateMain *__state) {
    __state->newSection = malloc(sizeof(TSection));
    __state->previousSection = malloc(sizeof(TSection));
    __state->executionSection = malloc(sizeof(TSection));
    __state->checkSection = malloc(sizeof(TSection));
    __state->isBegin = true;
    __state->newSection->std = false;
    __state->previousSection->std = false;
    __state->executionSection->std = false;
    __state->checkSection->std = false;
    __state->executionSection->std_init = true;
    __state->checkSection->std_finish = true;
}

void updateSection (TSection *__state) {
    if (!__state->std_init) __state->std_init = true;
    else if (__state->std_init && __state->std_finish) {
        __state->std_init = false;
        __state->std_finish = false;
    }
}

void checkState (TStateMain *__state) {
    if (__state->newSection->std || __state->previousSection->std || __state->executionSection->std || __state->checkSection->std)
        __state->isBegin = false;
    else __state->isBegin = true;

    if (!__state->isBegin) {
        __state->newSection->std = !__state->isPreviousSection ? true : false;
        __state->previousSection->std = __state->isPreviousSection && __state->executionSection->std_init && __state->checkSection->std_init ? true : false;
        __state->executionSection->std = __state->isPreviousSection && !__state->executionSection->std_init ? true : false;
        __state->checkSection->std = __state->isPreviousSection && !__state->checkSection->std_init ? true : false;
    }

    if (__state->newSection->std) goto NewSection;
    else if(__state->previousSection->std) goto PreviousSection;
    else if (__state->executionSection->std) goto ExecutionSection;
    else if (__state->checkSection->std) goto CheckSection;
    else if (!__state->previousSection->std && !__state->newSection->std) goto EndVerification;

    NewSection:
        updateSection(__state->newSection);
        goto EndVerification;

    PreviousSection:
        updateSection(__state->previousSection);
        goto EndVerification;

    ExecutionSection:
        updateSection(__state->executionSection);
        goto EndVerification;

    CheckSection:
        updateSection(__state->checkSection);
        goto EndVerification;

    EndVerification: ;
}
