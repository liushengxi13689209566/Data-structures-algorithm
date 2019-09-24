class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        Node *node = head;
        //1. 将复制节点添加到原节点后面
        while (node != nullptr)
        {
            Node *copy = new Node(node->val, nullptr, nullptr);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }

        //2. 复制random节点
        node = head;
        while (node != nullptr)
        {
            if (node->random != nullptr)
            {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }

        //3. 分离链表
        node = head;
        Node *newHead = head->next;
        Node *newNode = newHead;
        while (node != nullptr)
        {
            node->next = node->next->next;
            if (newNode->next != nullptr)
            {
                newNode->next = newNode->next->next;
            }
            node = node->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};