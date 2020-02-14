//
// Created by Wu Alex on 2020/2/14.
//

#ifndef NEWFREERTOS_LIST_H
#define NEWFREERTOS_LIST_H
#include "portmacro.h"

struct xLIST_ITEM
{
    TickType_t xItemValue;  /*辅助值，用于帮助节点做顺序排列*/
    struct xLIST_ITEM * pxNext; /*指向链表下一个节点*/
    struct xLIST_ITEM * pxPrevious; /*指向链表前一个节点*/
    void * pvOwner; /*指向拥有该节点的内核对象，即该节点内嵌在哪个数据结构中，属于哪个数据结构的一个成员*/
    void * pvContainer; /*指向该节点所在的链表，通常指向链表的根节点*/
};
typedef struct xLIST_ITEM ListItem_t; //节点数据类型重定义

struct xMINI_LIST_ITEM
{
    TickType_t xItemValue; /*辅助值，用于帮助节点做升序排列*/
    struct xLIST_ITEM * pxNext; /*指向链表下一个节点*/
    struct xLIST_ITEM * pxPrevious; /*指向链表前一个节点*/
};
typedef struct xMINI_LIST_ITEM MiniListItem_t; /*精简节点数据类型重定义*/


/*链表根节点数据结构定义*/
typedef struct xLIST
{
    UBaseType_t uxNumberOfItems; /*链表节点计数器，用于表示该链表下有多少个节点，根节点除外*/
    ListItem_t* pxIndex;    /*链表节点索引指针，用于遍历节点*/
    /*链表最后一个节点 链表是首位相连的，是一个圈，首就是尾，尾就是首，就是链表的最后一个节点，实际就是链表的第一个节点
     * 我们称之为生产者。该生产者的数据类型是一个精简的节点。*/
    MiniListItem_t xListEnd;
}List_t;

//链表节点初始化
void vListInitialiseItem(ListItem_t* const pxItem);

//链表根节点初始化
void vListInitialise(List_t * const pxList);

//将节点插入到链表的尾部
void vListInsertEnd(List_t *const pxList, ListItem_t * const pxNewListItem);

#endif //NEWFREERTOS_LIST_H
