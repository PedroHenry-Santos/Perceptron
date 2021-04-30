/*
* Autor: Pedro Henrique Viana dos Santos.
* Purpose: Methods for the operation of the main block.
* Language: C.
*/

/*
* Checks whether files exist within 'data'.
*
* This function returns a boolean.
*/
bool checkDirectory ();

bool checkDirectory () {
    int check = ctfp("./data");

    if (check > 0) return true;
    else {
        printf(ANSI C_YELLOW END"\n\n                        * Nao foi encontrado nenhum arquivo *"RESET);
        return false;
    }
}

/*
* Search the training data of the file chosen by the user
* and provides the application.
*
* This function returns false.
*/
bool fillsPreviousSectionValues (TPcpt *__data, TStateMain *__state) {
    FILE *fp;

    char path[PATH_NAME_SIZE * TWO];

    strcat(path, "data/");
    strcat(path, __state->dataDirectories->file);

    fp = fopen(path, "rb");

    if (fp) {
        fscanf(fp, "%s\n", __data->username);
        fscanf(fp, "%d %d\n", &__data->size, &__data->era);
        __data->w_current = malloc(__data->size * sizeof(float));
        int verif = fread(__data->w_current, sizeof(float), __data->size, fp);
        if (verif != __data->size || ferror(fp)) {
            sclean();
            displaysHeader(__state->isBegin);
            displaysFailedRead();
            return true;
        }
    } else {
        sclean();
        displaysHeader(__state->isBegin);
        displaysFailedRead();
        return true;
    }

    fclose(fp);
    return false;
}
