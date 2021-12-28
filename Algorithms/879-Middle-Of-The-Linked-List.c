/**
 * @author HEXDude
 * @date 12/28/21
 * @description 
 * @reference 
 * @conclusion 
 */

//Local Part Start
//Local Part end

//Submit Part Start
struct ListNode* middleNode(struct ListNode* head){
    //因为结构体定义的单链表,不能简单的通过下标来寻找了
    //可以定义快慢指针来解决,快指针每次走两个节点,而慢
    //指针每次都一个节点,这样,当快指针走到尽头时,慢指针
    //一定是停在中间位置的
    struct ListNode * slow = head;
    struct ListNode * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//Submit Part End

