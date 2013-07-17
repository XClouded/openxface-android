#ifndef XF_FILE_H
#define XF_FILE_H

#ifdef __cplusplus
extern "C" {
#endif

#define XF_FILE_RDONLY  0x00   ///<ֻ��
#define XF_FILE_WRONLY  0x01   ///<ֻд
#define XF_FILE_RDWR    0x02   ///<����д
#define XF_FILE_APPEND  0x10   ///<׷��
#define XF_FILE_CREAT   0x40   ///<����

#define XF_FILE_BEGIN           0///<�ļ���ʼ
#define XF_FILE_CURRENT         1///<�ļ���ǰλ��
#define XF_FILE_END             2///<�ļ�����λ��

/** �ݹ�Ĵ���Ŀ¼����Ŀ¼·���а��������ڵ��ļ���ʱ��������Ӧ���ļ��С�
 *  @param[in] pDirPath:  Ŀ¼��·��������·�����ָ���Ϊ'/'��unicode���룬��β��'/'�����ַ�'\0'��β����
 *  @return
 *     -   XF_OK:       �ɹ��������ɹ����Ӧ���ļ����Ѿ����ڣ�
 *     -   XF_ERROR:    ʧ��
 */
int XF_FILE_mkdir(const unsigned short* pDirPath);

typedef void * XF_File;    ///<�ļ����

/** ���ļ�
 *  @param[in] pFilePath:  �ļ�·��������·�����ָ���Ϊ'/'��unicode���룬���ַ�'\0'��β��
 *  @param[in] flags:      �ļ��Ĵ򿪷�ʽ��֧�����¼��ִ򿪷�ʽ��
 *  \n XF_FILE_RDONLY      ��ֻ���ķ�ʽ���ļ���
 *  \n XF_FILE_WRONLY      ��ֻд�ķ�ʽ���ļ�������������ļ����Ѿ����ڵ����ݣ����׼C��API��һ����
 *  \n XF_FILE_RDWR        �Զ�д�ķ�ʽ���ļ���
 *  \n XF_FILE_CREAT       ����ļ������ڣ��������ļ���
 *  \n ע��
 *  \n 1 XF_FILE_RDONLY��XF_FILE_WRONLY��XF_FILE_RDWR���ַ�ʽ���ɺ��á�
 *  \n 2 ���Ҫʹ��XF_FILE_CREAT��������ǰ���ַ�ʽ��һ�ֺ��á�
 *  @return
 *     - NOT NULL:  �ɹ����ļ������
 *     - NULL:      ʧ��
 */
XF_File XF_FILE_open(const unsigned short* pFilePath, unsigned int flags);

/** �ر��ļ�
 *  @param[in] fileHandle:  �ļ������XF_FILE_open����ֵ��
 *  @return
 *     -   XF_OK:       �ɹ�
 *     -   XF_ERROR:    ʧ��
 */
int XF_FILE_close(const XF_File fileHandle);

/** �Ա��򿪵��ļ�����д�������ļ�ϵͳ���ӻ�����buffer��дcount���ֽڵ����ļ��У����ҴӸ��ļ��ĵ�ǰ
 *  ����λ�ÿ�ʼд�룬��������ɹ������ļ�ϵͳ���ý�����һ�����ڻ��ǵ���0����������ʾʵ��д�������
 *  �ֽ������������ʧ�ܣ��򷵻�XF_ERROR��
 *  @param[in] fileHandle:  �ļ������XF_FILE_open()����ֵ����
 *  @param[in] pBuffer:     Ҫд�����ݣ����棩��
 *  @param[in] size:        Ҫд������ݳ��ȣ���λByte����
 *  @return
 *     -   >=0:         �ɹ�(ʵ��д��������ֽ���)
 *     -   XF_ERROR:    ʧ��
 */
int XF_FILE_write(const XF_File fileHandle, const void *pBuffer, unsigned int size);

/** �ƶ��ļ�ָ��,���offset�������ļ�����Ĵ�С������������XF_ERROR���ļ�ָ��λ�ò��䡣
 *  @param[in] fileHandle:  �ļ������XF_FILE_open()�ķ���ֵ����
 *  @param[in] offset:      ���ļ���ͷΪ��׼��ƫ��������λByte�������ֵΪ������ֱ�ӷ���ʧ�ܣ�
 *  @param[in] moveMethod:
 *  XF_FILE_BEGIN - �趨λ�õ��� offset(Ĭ��).
 *  XF_FILE_CURRENT - �趨λ��Ϊ��ǰλ�ü��� offset.
 *  XF_FILE_END - �趨λ��Ϊ�ļ�ĩβ���� offset (Ҫ�ƶ����ļ�β֮ǰ��λ��, offset������һ����ֵ).
 *  @return
 *     -   XF_OK:       �ɹ�
 *     -   XF_ERROR:    ʧ��
 */
int XF_FILE_seek(const XF_File fileHandle, int offset, int moveMethod);

/** �Ա��򿪵��ļ����ж��������ļ�ϵͳ���Ӹ��ļ��ĵ�ǰ����λ�ÿ�ʼ����length���ֽڵ����ݵ�������buffer�У�
 *  ��������ɹ������ļ�ϵͳ���ý�����һ�����ڻ��ǵ���0����������ʾʵ�ʶ����������ֽ������������ʧ�ܣ��򷵻�XF_ERROR��
 *  @param[in] fileHandle:  �ļ������XF_FILE_open()����ֵ����
 *  @param[out] pBuffer:    ��ȡ����������ɵ����߷�����ͷţ���
 *  @param[in] length:      Ҫ��ȡ�ĳ��ȣ��ɵ����߱�֤���湻�ò�Խ�磩����λByte��
 *  @return
 *     -   >=0:         �ɹ�(ʵ�ʶ����������ֽ���)
 *     -   XF_ERROR:    ʧ��
 */
int XF_FILE_read(const XF_File fileHandle, void *pBuffer, unsigned int length);

/** ��ȡ�ļ�ָ�뵱ǰƫ��������XF_FILE_seek()��Ӧ����
 *  @param[in] fileHandle:  �ļ������XF_FILE_open()����ֵ����
 *  @return
 *     -   >=0:         �ɹ�(�ļ�ָ������ļ�ͷ��ƫ����,��λByte)
 *     -   XF_ERROR:    ʧ��
 */
int XF_FILE_tell(const XF_File fileHandle);

/**�ж��ļ��Ƿ���һ��Ŀ¼��
*  @param[in] pPath:        �ļ����У�·��������·�����ָ���Ϊ'/'��unicode���룬���ַ�'\0'��β��
*  @return
*     -   XF_TRUE/XF_FALSE:         �ɹ�
*     -   XF_ERROR:                 ʧ��
*/
int XF_FILE_isDirectory(const unsigned short *pPath);

/**��ȡ�ļ���С����λByte)��
 *  @param[in] fileHandle:  �ļ������XF_FILE_open()����ֵ����
 *  @return
 *     -   >=0:         �ɹ����ļ��Ĵ�С��
 *     -   XF_ERROR:    ʧ��
 */
int XF_FILE_getLength(const XF_File fileHandle);

#if defined(ANDROID) || defined(STLinux)
#endif

#ifdef __cplusplus
}
#endif


#endif
