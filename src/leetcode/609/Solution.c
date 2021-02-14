#include "Solution.h"

/*
第一步 预处理，要用split存下文件目录数组和文件数组
第二步 扫描所有文件，对于每个文件计算其文件内容hash，如果确认没有冲突的话（只需要和那个hash位置的其中一个文件内容比较即可）就将该文件的文件目录ID放到另一个文件目录ID的hashset中
第三步 从文件目录ID的hashset中提取出答案
*/
/* MAX_FILE_NUM越大性能就越好，因为冲突发生次数就会越低 */
#define MAX_FILE_NAME 50
#define MAX_CONTENT 51
#define MAX_FILE_NUM 40000

typedef struct {
    int dirID;
    char name[MAX_FILE_NAME];
    char content[MAX_CONTENT];
} File_t;

typedef struct {
    int *FileID;
    int num;
} HashContent_t;

/* a hash function mapping content of a file to a int number*/
int Str2Num(char *s)
{
    int hash = 1;
    for (int i = 0; i < strlen(s); i++) {
        hash = (hash * s[i]) % MAX_FILE_NUM;
    }
    for (int i = 0; i < strlen(s); i++) {
        hash = (hash + s[i]) % MAX_FILE_NUM;
    }
    return hash;
}

void StoreFileNameAndContent(char *fileNameAndContent, File_t *file)
{
    bool isContent = false;
    for (int i = 0, t = 0; i < strlen(fileNameAndContent); i++) {
        if (isContent) {
            if (fileNameAndContent[i] == ')') {
                file->content[t] = '\0';
                break;
            }
            file->content[t++] = fileNameAndContent[i];
        } else {
            if (fileNameAndContent[i] == '(') {
                file->name[i] = '\0';
                isContent = true;
                continue;
            }
            file->name[i] = fileNameAndContent[i];
        }
    }
}

void Preprocess(char **paths, int pathsSize, File_t *files, int *fileNum, char **dirs)
{
    *fileNum = 0;
    char delimeter[2] = " ";
    for (int i = 0; i < pathsSize; i++) {
        dirs[i] = strtok(paths[i], delimeter);
        char *fileNameAndContent = strtok(NULL, delimeter);
        while (fileNameAndContent != NULL) {
            files[*fileNum].dirID = i;
            StoreFileNameAndContent(fileNameAndContent, &files[*fileNum]);
            (*fileNum)++;
            fileNameAndContent = strtok(NULL, delimeter);
        }
    }
}

bool HasConflict(int h, HashContent_t *hashContent, File_t *files, int newFid)
{
    if (hashContent[h].num == 0) {
        return false;
    }
    int oldFid = hashContent[h].FileID[0];
    if (strlen(files[oldFid].content) != strlen(files[newFid].content)) {
        return true;
    }
    for (int i = 0; i < strlen(files[oldFid].content); i++) {
        if (files[oldFid].content[i] != files[newFid].content[i]) {
            return true;
        }
    }
    return false;
}

void HashFileContent(File_t *files, int fileNum, HashContent_t *hashContent)
{
    for (int i = 0; i < MAX_FILE_NUM; i++) {
        hashContent[i].num = 0;
        hashContent[i].FileID = NULL;
    }
    for (int i = 0; i < fileNum; i++) {
        int h = Str2Num(files[i].content);
        // printf("%d\n", h);
        /* check conflict */
        while (HasConflict(h, hashContent, files, i)) {
            // printf("Has Conflict!\n");
            h = (h + 1) % MAX_FILE_NUM;
        }
        hashContent[h].FileID = realloc(hashContent[h].FileID, sizeof(int) * (hashContent[h].num + 1));
        hashContent[h].FileID[hashContent[h].num] = i;
        hashContent[h].num++;
    }
}

void RecordAns(char ****ans, int *returnSize, int **returnColumnSizes, HashContent_t *hashContent, File_t *files, char **dirs)
{
    *returnSize = 0;
    for (int i = 0; i < MAX_FILE_NUM; i++) {
        if (hashContent[i].num > 1) {
            (*returnSize)++;
        }
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    *ans = (char***)malloc(sizeof(char**) * (*returnSize));
    for (int i = 0, t = 0; i < MAX_FILE_NUM; i++) {
        if (hashContent[i].num > 1) {
            (*returnColumnSizes)[t] = hashContent[i].num;
            // printf("%d\n", hashContent[i].num);
            (*ans)[t] = (char**)malloc(sizeof(char*) * hashContent[i].num);
            for (int j = 0; j < hashContent[i].num; j++) {
                int fid = hashContent[i].FileID[j];
                int did = files[fid].dirID;
                int len = strlen(dirs[did]) + strlen(files[fid].name) + 2;
                // printf("%d %d %d\n", fid, did, len);
                // printf("%d\n", ((*ans)[t])[j] == NULL);
                (*ans)[t][j] = (char*)malloc(sizeof(char) * len);
                strcpy((*ans)[t][j], dirs[did]);
                strcat((*ans)[t][j], "/");
                strcat((*ans)[t][j], files[fid].name);
                // printf("%s\n", (*ans)[t][j]);
            }
            t++;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** findDuplicate(char ** paths, int pathsSize, int* returnSize, int** returnColumnSizes)
{
    char ***ans = NULL;
    char **dirs = (char*)malloc(sizeof(char*) * pathsSize);
    int fileNum;
    File_t files[MAX_FILE_NUM];
    HashContent_t hashContent[MAX_FILE_NUM];
    Preprocess(paths, pathsSize, files, &fileNum, dirs);
    HashFileContent(files, fileNum, hashContent);
    RecordAns(&ans, returnSize, returnColumnSizes, hashContent, files, dirs);
    free(dirs);
    return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/find-duplicate-file-in-system/solution/609cyu-yan-by-yewenhao-xohx/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。