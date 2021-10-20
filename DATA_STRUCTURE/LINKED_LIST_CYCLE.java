/**
 * @author HEXDude
 * @date 2021/10/20
 * @see <a href = "https://leetcode-cn.com/problems/linked-list-cycle/">Linked list cycle</a>
 */
package DATA_STRUCTURE;

public class LINKED_LIST_CYCLE {
    public static void main(String[] args) {
        int x = 3;
        ListNode nodes = new Listnode(x);
        System.out.println(1);
    }
}

/**
 * Definition for singly-linked list. class ListNode { int val; ListNode next;
 * ListNode(int x) { val = x; next = null; } }
 */
class Solution_LINKED_LIST_CYCLE {
    public boolean hasCycle(ListNode head) {
        // 走过的节点
        Set<ListNode> nodes = new HashSet<ListNode>();
        while (head != null) {
            // 如果已存在节点，说明存在环
            if (!nodes.add(head)) {
                return true;
            }
            head = head.next;
        }
        return false;
    }
}

/**
 * InnerLINKED_LIST_CYCLE
 */
class Listnode {
    int val;
    Listnode next;

    Listnode(int x) {
        val = x;
        next = null;
    }
}
