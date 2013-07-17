#ifndef XF_MEMORY_H
#define XF_MEMORY_H

#ifdef __cplusplus 
extern "C" { 
#endif 

/**�����ڴ�顣
 * �Ӷ��з���һ����СΪsize�ֽڵ��ڴ�ռ䣬���û���㹻���ڴ�ռ��sizeΪ0������NULL�� 
 * @param[in] size:    ��Ҫ������ڴ�ռ��С����λByte��
 * @return
 *    -   NOT NULL: �ɹ����·�����ڴ��ַ��
 *    -   NULL:     ʧ��
 */
void * XF_MEM_malloc(unsigned int size);

/**���·����ڴ�飬��С�������ѷ����ڴ�顣�������·����ĵ�ַ������ԭ��ַ���ݿ�������λ���ϣ�
 * ����鲻�ܱ����·������sizeΪ0������NULL��
 * @param[in] pMemBlock ԭ�ڴ�ռ��ַ��ָ��ͨ������XF_MEM_malloc()��XF_MEM_calloc()��XF_MEM_realloc()�ѵõ����ڴ�飬
 *                      ���pMemBlock��һ����ָ�룬��ôXF_MEM_realloc()��XF_MEM_malloc()��ͬ�� 
 * @param[in] size ���·���Ŀռ��С
 * @return
 *    -   NOT NULL: �ɹ����·�����ڴ��ַ��
 *    -   NULL:     ʧ��
 */
void * XF_MEM_realloc(void *pMemBlock, unsigned int size);

/**�����������ڴ�顣
 * ����count������Ϊsize�������ռ䣬�ÿ鱻���Ϊ0�����û���㹻���ڴ�ռ����count��sizeΪ0���򷵻�NULL�� 
 * @param[in] count:   ����Ŀ����
 * @param[in] size:    ÿ��Ĵ�С����λByte��
 * @return
 *    -   NOT NULL: �ɹ����·�����ڴ��ַ��
 *    -   NULL:     ʧ��
 */
void * XF_MEM_calloc(unsigned int count, unsigned int size);

/**�ͷ��ڴ�顣
 * �ͷ���XF_MEM_malloc()��XF_MEM_calloc()��XF_MEM_realloc()����������������ڴ�ռ䣬��pMemBlockΪNULLʱ�����κβ����� 
 * @param[in] pMemBlock:     ��Ҫ�ͷŵ��ڴ�ռ��ַ
 */
void XF_MEM_free(void *pMemBlock);


#ifdef __cplusplus 
} 
#endif  

#endif
