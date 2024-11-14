#include "bflb_mtimer.h"
#include "board.h"
#include "fatfs_diskio_register.h"
#include "ff.h"

#define DBG_TAG "MAIN"
#include "log.h"

#include "shell.h"

FATFS fs;
__attribute((aligned(8))) static uint32_t workbuf[4096];

MKFS_PARM fs_para = {
    .fmt = FM_FAT32,     /* Format option (FM_FAT, FM_FAT32, FM_EXFAT and FM_SFD) */
    .n_fat = 1,          /* Number of FATs */
    .align = 0,          /* Data area alignment (sector) */
    .n_root = 1,         /* Number of root directory entries */
    .au_size = 512 * 32, /* Cluster size (byte) */
};



void filesystem_init(void)
{
    FRESULT ret;

    board_sdh_gpio_init();

    fatfs_sdh_driver_register();

    ret = f_mount(&fs, "/sd", 1);
    // ret = FR_NO_FILESYSTEM;

    if (ret == FR_NO_FILESYSTEM) {
        LOG_W("No filesystem yet, try to be formatted...\r\n");

        ret = f_mkfs("/sd", &fs_para, workbuf, sizeof(workbuf));

        if (ret != FR_OK) {
            LOG_F("fail to make filesystem %d\r\n", ret);
            _CALL_ERROR();
        }

        if (ret == FR_OK) {
            LOG_I("done with formatting.\r\n");
            LOG_I("first start to unmount.\r\n");
            ret = f_mount(NULL, "/sd", 1);
            LOG_I("then start to remount.\r\n");
        }
    } else if (ret != FR_OK) {
        LOG_F("fail to mount filesystem,error= %d\r\n", ret);
        LOG_F("SD card might fail to initialise.\r\n");
        _CALL_ERROR();
    } else {
        LOG_D("Succeed to mount filesystem\r\n");
    }

    if (ret == FR_OK) {
        LOG_I("FileSystem cluster size:%d-sectors (%d-Byte)\r\n", fs.csize, fs.csize * 512);
    }
}

#define SDU_DATA_CHECK 1

char test_data[] =
    "I've been reading books of old \r\n\
    The legends and the myths \r\n\
    Achilles and his gold \r\n\
    Hercules and his gifts \r\n\
    Spiderman's control \r\n\
    And Batman with his fists\r\n\
    And clearly I don't see myself upon that list\r\n\
    But she said, where'd you wanna go?\r\n\
    How much you wanna risk?\r\n\
    I'm not looking for somebody\r\n\
    With some superhuman gifts\r\n\
    Some superhero\r\n\
    Some fairytale bliss\r\n\
    Just something I can turn to\r\n\
    Somebody I can kiss\r\n\
    I want something just like this\r\n\r\n";

BYTE RW_Buffer[32 * 1024];
#if SDU_DATA_CHECK
BYTE Check_Buffer[sizeof(RW_Buffer)] = { 0 };
#endif


uint32_t i, j;



void fatfs_read_jpg()
{
    FRESULT ret;
    FIL fnew;
    UINT fnum;


   memcpy(&RW_Buffer, test_data, sizeof(test_data));


    /* write test */
    LOG_I("\r\n******************** be about to write test... **********************\r\n");
    ret = f_open(&fnew, "/sd/test_file0.jpg", FA_CREATE_ALWAYS | FA_WRITE);
    if (ret == FR_OK) {
        /*write into file*/
        ret = f_write(&fnew, RW_Buffer, sizeof(RW_Buffer), &fnum);
        //ret = f_write(&fnew, pic, sizeof(pic), &fnum);

        /* close file */
        ret |= f_close(&fnew);


        if (ret == FR_OK) {
            LOG_I("Write Test Succeed! \r\n");
            
        } else {
            LOG_F("Fail to write files(%d) num:%d\n", ret, i);
        }
    } else {
        LOG_F("Fail to open or create files: %d.\r\n", ret);
    }

    /* read test */
    LOG_I("\r\n******************** be about to read test... **********************\r\n");
    ret = f_open(&fnew, "/sd/test_file1.jpg", FA_OPEN_EXISTING | FA_READ);
    if (ret == FR_OK) {

        ret = f_read(&fnew, RW_Buffer, sizeof(RW_Buffer), &fnum);
        
        /* close file */
        ret |= f_close(&fnew);


        if (ret == FR_OK) {
            LOG_I("Read Test Succeed! \r\n");

        } else {
            LOG_F("Fail to read file: (%d), num:%d\n", ret, i);

        }
    } else {
        LOG_F("Fail to open files.\r\n");
    }

    /* write test again */
    LOG_I("\r\n******************** be about to write test again... **********************\r\n");
    ret = f_open(&fnew, "/sd/test_file1.txt", FA_CREATE_ALWAYS | FA_WRITE);
    if (ret == FR_OK) {

        /*write into file*/
        ret = f_write(&fnew, RW_Buffer, sizeof(RW_Buffer), &fnum);

        /* close file */
        ret |= f_close(&fnew);

        if (ret == FR_OK) {
            LOG_I("Write Test Succeed! \r\n");
            
        } else {
            LOG_F("Fail to write files(%d) num:%d\n", ret, i);
        }
    } else {
        LOG_F("Fail to open or create files: %d.\r\n", ret);
    }


}

static void sd_read_jpg(int argc, char **argv)
{

    FRESULT ret;
    FIL fnew;
    UINT fnum;


    memcpy(&RW_Buffer, test_data, sizeof(test_data));


    /* write test */
    LOG_I("\r\n******************** be about to write test... **********************\r\n");
    ret = f_open(&fnew, "/sd/test_file0.jpg", FA_CREATE_ALWAYS | FA_WRITE);
    if (ret == FR_OK) {
        /*write into file*/
        ret = f_write(&fnew, RW_Buffer, sizeof(RW_Buffer), &fnum);
        //ret = f_write(&fnew, pic, sizeof(pic), &fnum);

        /* close file */
        ret |= f_close(&fnew);


        if (ret == FR_OK) {
            LOG_I("Write Test Succeed! \r\n");
            
        } else {
            LOG_F("Fail to write files(%d) num:%d\n", ret, i);
        }
    } else {
        LOG_F("Fail to open or create files: %d.\r\n", ret);
    }

    /* read test */
    LOG_I("\r\n******************** be about to read test... **********************\r\n");
    ret = f_open(&fnew, "/sd/test_file1.jpg", FA_OPEN_EXISTING | FA_READ);
    if (ret == FR_OK) {

        ret = f_read(&fnew, RW_Buffer, sizeof(RW_Buffer), &fnum);
        
        /* close file */
        ret |= f_close(&fnew);


        if (ret == FR_OK) {
            LOG_I("Read Test Succeed! \r\n");

        } else {
            LOG_F("Fail to read file: (%d), num:%d\n", ret, i);

        }
    } else {
        LOG_F("Fail to open files.\r\n");
    }

    /* write test again */
    LOG_I("\r\n******************** be about to write test again... **********************\r\n");
    ret = f_open(&fnew, "/sd/test_file1.txt", FA_CREATE_ALWAYS | FA_WRITE);
    if (ret == FR_OK) {

        /*write into file*/
        ret = f_write(&fnew, RW_Buffer, sizeof(RW_Buffer), &fnum);

        /* close file */
        ret |= f_close(&fnew);

        if (ret == FR_OK) {
            LOG_I("Write Test Succeed! \r\n");
            
        } else {
            LOG_F("Fail to write files(%d) num:%d\n", ret, i);
        }
    } else {
        LOG_F("Fail to open or create files: %d.\r\n", ret);
    }


}


#ifdef CONFIG_SHELL
#include <shell.h>

int cmd_sd_read_jpg(int argc, char **argv)
{
    sd_read_jpg(argc, argv);

    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_sd_read_jpg, sd_read_jpg, sd read jpg test);
#endif





//--------------------------------------------------------------------------------------------------------------------sd_tree


FIL file;
UINT filenum;
DIR filedir;
uint32_t fileSize;

static void print_file_tree(const char* path, int level) {
    FRESULT ret;
    FILINFO fileInfo;
    DIR subDir;
    char currentPath[256];

    // 打开当前层级的目录
    ret = f_opendir(&subDir, path);
    if (ret != FR_OK) {
        return;
    }

    while (1) {
        ret = f_readdir(&subDir, &fileInfo);

        // 读取目录项出错或者目录项读取完毕，退出循环
        if (ret != FR_OK || fileInfo.fname[0] == 0) {
            break;
        }

        // 忽略"."和".."目录
        if (fileInfo.fname[0] == '.' && (fileInfo.fname[1] == 0 ||
            (fileInfo.fname[1] == '.' && fileInfo.fname[2] == 0))) {
            continue;
        }

        // 打印缩进和文件路径
        printf("%*s%s/%s\r\n", level * 4, "", path, fileInfo.fname);

        // 如果是文件夹，则递归进入子文件夹并进行相同的操作
        if (fileInfo.fattrib & AM_DIR) {
            // 构建子文件夹路径
            sprintf(currentPath, "%s/%s", path, fileInfo.fname);
            // 递归打印子文件夹的目录结构
            print_file_tree(currentPath, level + 1);
        }
    }

    f_closedir(&subDir);
}

static void sd_tree(int argc, char **argv) {
    FRESULT ret = f_opendir(&filedir, "/sd");

    printf("display file tree /sd/...\r\n");
    if (ret == FR_OK) {
        print_file_tree("/sd", 0);
        f_closedir(&filedir);
    }
}


#ifdef CONFIG_SHELL
#include <shell.h>

int cmd_sd_tree(int argc, char **argv)
{
    sd_tree(argc, argv);

    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_sd_tree, sd_tree, sd print file tree);
#endif

//--------------------------------------------------------------------------------------------------------------------sd_read_post
extern unsigned char* pic;

static void sd_read_post(int argc, char **argv)
{
    FRESULT ret;

    char* filepath = "/sd/test_jpg1.jpg";
    if (argc > 1) {
        filepath = argv[1];
    }
    else
    {
        printf("[USAGE]: sd_tree /sd/test_jpg1.jpg  \r\n");
    }


    /* read FILE */
    LOG_I("\r\n******************** be about to read %s **********************\r\n", filepath);
    ret = f_open(&file, filepath, FA_OPEN_EXISTING | FA_READ);
    if (ret == FR_OK) {

        memset(RW_Buffer, 0, sizeof(RW_Buffer));
        ret = f_read(&file, RW_Buffer, sizeof(RW_Buffer), &filenum);
        
        /* close file */
        ret |= f_close(&file);
        
        if (ret == FR_OK) {
            LOG_I("Read Succeed! \r\n");
            
            fileSize = f_size(&file);
            printf("fileSize: %d\r\n", fileSize);

            // 打印读取到的数据
            pic = (char*)malloc(3 * filenum + 1);
            for (int i = 0; i < filenum; i++) {
                // 转换二进制数据为字符形式并保存到字符串中
                sprintf(&pic[3 * i], "%02X ", RW_Buffer[i]);
                printf("%02X ", RW_Buffer[i]);
            }

            pic[3 * filenum] = '\0';  // 添加 pic 字符串结尾的空字符

            printf("\r\n");
            printf("BufferSize: %d\r\n", filenum);

            // RW_Buffer[filenum] = '\0';
            
            printf("%s ", pic);
        } else {
            LOG_F("Fail to read file: (%d), num:%d\n", ret, i);

        }
    } else {
        LOG_F("Fail to open files.\r\n");
    }

}

#ifdef CONFIG_SHELL
#include <shell.h>

int cmd_sd_read_post(int argc, char **argv)
{
    sd_read_post(argc, argv);

    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_sd_read_post, sd_read_post, sd read post file);
#endif