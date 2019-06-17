package com.company.list;

import java.util.Stack;

public class SingleList {
    public static void main(String[] args){
        Node hero1 = new Node(1, "宋江", "及时雨");
        Node hero2 = new Node(2, "卢俊义", "玉麒麟");
        Node hero3 = new Node(3, "吴用", "智多星");
        Node hero4 = new Node(4, "林冲", "豹子头");

        //创建要给链表
        SingleLinkedList singleLinkedList = new SingleLinkedList();
        singleLinkedList.add(hero1);
        singleLinkedList.add(hero4);
        singleLinkedList.add(hero2);
        singleLinkedList.add(hero3);

        System.out.println("原来链表的情况~~");
        singleLinkedList.list();

    }


    public static reversePrint(Node node){
        if (node.next == null){
            return;
        }
        Stack<Node> stack = new Stack<Node>();
        Node cur = node.next;
        while (cur != null){
            stack.push(cur);
            cur = cur.next;
        }
        while (stack.size() > 0) {
            System.out.println(stack.pop());
        }
    }


    public static void reversetList(Node head){
        if(head.next == null || head.next.next == null) {
            return ;
        }

        Node cur = head.next;
        Node next = null;
        Node reversetHead = new Node(0, "", "");

        while (cur != null){
            next = cur.next;
            cur.next = reversetHead.next;
            reversetHead.next = cur;
            cur = next;
        }
        head.next = reversetHead.next;
    }
}

class SingleLinkedList {
    private Node head = new Node(0,"","");
    public Node getHead() {
        return head;
    }
    public void add(Node node) {
        Node temp = head;
        while (true) {
            if (temp.next == null) {
                break;
            }
            temp = temp.next;
        }
        temp.next = node;
    }
    public void addByOrder(Node node) {
        Node temp = head;
        boolean flag = false;
        while (true){
            if (temp.next == null){
                break;
            }
            if (temp.next.no > head.no){
                break;
            }else if(temp.next.no == node.no){
                flag = true;
                break;
            }
            temp = temp.next;
        }
        if (flag){
            System.out.printf("准备插入的英雄的编号 %d 已经存在了, 不能加入\n", heroNode.no);
        }else{
            node.next = temp.next;
            temp.next = node;
        }
    }

    public void update(Node node){
        if (head.next == null) {
            System.out.println("链表为空~");
            return;
        }
        Node temp = head.next;
        boolean flag = false;
        while (true) {
            if (temp == null) {
                break;
            }
            if (temp.no == node.no){
                flag = true;
                break;
            }
            temp = temp.next;
        }
        if (flag){
            temp.name = node.name;
            temp.nickName = node.nickName;
        }else{
            System.out.printf("没有找到 编号 %d 的节点，不能修改\n", node.no);
        }
    }


    public void del(int no) {
        Node temp = head;
        boolean flag = false;
        while (true){
            if (temp.next == null){
                break;
            }
            if (temp.next.no == no){
                flag = true;
                break;
            }
            temp = temp.next;
        }
        if (flag){
            temp.next = temp.next.next;
        }else{
            System.out.printf("要删除的 %d 节点不存在\n", no);
        }
    }


    public void list() {
        if (head.next == null){
            System.out.println("链表为空");
            return;
        }
        Node temp = head.next;
        while (true) {
            if (temp == null) {
                break;
            }
            System.out.println(temp);
            temp = temp.next;
        }
    }

}

class Node {
    public int no;
    public String name;
    public String nickName;
    public Node next;

    public Node(int no,String name,String nickName){
        this.no = no;
        this.name = name;
        this.nickName = nickName;
    }
    @Override
    public String toString() {
        return "HeroNode [no=" + no + ", name=" + name + ", nickname=" + nickname + "]";
    }
}