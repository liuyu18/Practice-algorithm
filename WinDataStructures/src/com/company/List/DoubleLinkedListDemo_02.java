package com.company.List;

public class DoubleLinkedListDemo_02 {


    public static void main(String[] args) {
        // 测试
        System.out.println("双向链表的测试");
        // 先创建节点

        HeroNode hero1 = new HeroNode(1, "宋江", "及时雨");
        HeroNode hero2 = new HeroNode(2, "卢俊义", "玉麒麟");
        HeroNode hero3 = new HeroNode(3, "吴用", "智多星");
        HeroNode hero4 = new HeroNode(4, "林冲", "豹子头");
        // 创建一个双向链表
        DoubleLinkedList doubleLinkedList = new DoubleLinkedList();
        doubleLinkedList.add(hero1);
        doubleLinkedList.add(hero2);
        doubleLinkedList.add(hero3);
        doubleLinkedList.add(hero4);

        doubleLinkedList.list();

        // 修改
        HeroNode newHeroNode = new HeroNode(4, "公孙胜", "入云龙");
        doubleLinkedList.update(newHeroNode);
        System.out.println("修改后的链表情况");
        doubleLinkedList.list();

        // 删除
        doubleLinkedList.del(3);
        System.out.println("删除后的链表情况~~");
        doubleLinkedList.list();



    }

}


    class DoubleLinkedList{
        private HeroNode head = new HeroNode(0,"","");

        public HeroNode getHead(){
            return head;
        }

        public void list(){
            if (head.next == null){
                System.out.println("链表为空");
                return;
            }
            HeroNode temp = head.next;
            while (true){
                if (temp == null){
                    break;
                }
                System.out.println(temp);
                temp = temp.next;
            }
        }

        public void add(HeroNode heroNode){
            HeroNode temp = head;
            while (true){
                if (temp.next == null){
                    break;
                }
                temp = temp.next;
            }
            temp.next = heroNode;
            heroNode.pre = temp;
        }

        public void update(HeroNode newHeroNode){
            if (head.next == null){
                System.out.println("链表为空");
                return;
            }

            HeroNode temp = head.next;
            boolean flag = false;
            while (true){
                if (temp == null){
                    break;
                }
                if (temp.no == newHeroNode.no){
                    flag = true;
                    break;
                }
                temp = temp.next;
            }
            if (flag){
                temp.name = newHeroNode.name;
                temp.nickName = newHeroNode.nickName;
            }else{
                System.out.printf("没有找到 编号 %d 的节点，不能修改\n", newHeroNode.no);
            }
        }

        public void del(int no){
            if (head.next == null){
                System.out.println("链表为空，无法删除");
                return;
            }
            HeroNode temp = head.next;
            boolean flag = false;
            while (true){
                if (temp == null){
                    break;
                }
                if (temp.no == no){
                    flag = true;
                    break;
                }
                temp = temp.next;
            }
            if (flag){
                temp.pre.next = temp.next;
                if (temp.next != null){
                    temp.next.pre = temp.pre;
                }
            }else{
                System.out.printf("要删除的 %d 节点不存在\n", no);
            }
        }

    }

    class HeroNode {
        public int no;
        public String name;
        public String nickName;
        public HeroNode next;
        public HeroNode pre;

        public HeroNode(int no ,String name,String nickName){
            this.no = no;
            this.name = name;
            this.nickName = nickName;
        }

        public String toString(){
            return "HeroNode [no=" + no + ", name=" + name + ", nickname=" + nickName + "]";
        }
    }

