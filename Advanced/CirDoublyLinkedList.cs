using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicPlayerAutoPlaylist
{
    class CirDoublyLinkedList<T>
    {
        private Node<T> head;
        public Node<T> Head
        {
            get { return head; }
            set { head = value; }
        }


        public CirDoublyLinkedList()
        {
            this.head = null;
        }

        public void addFirst(T data)
        {
            Node<T> newNode = new Node<T>(data);
            if (this.head == null)
            {
                newNode.Next = newNode;
                newNode.Prev = newNode;
                this.head = newNode;
            }
            else
            {
                Node<T> tail = this.head.Prev;
                //chinh newNode nam giua head va tail(dung ca th co 1)
                newNode.Next = this.head;
                newNode.Prev = tail;

                //cap nhat head va tail?
                this.head.Prev = newNode;
                tail.Next = newNode;// chinh sua field cua tail thi field do cua head cung doi() //giong nhu delete a thi b van con nhung cac field cua b bi xoa

                //doi chuc vu 
                this.head = newNode;
            }
        }

        public void addLast(T data)
        {
            Node<T> newNode = new Node<T>(data);
            if (this.head == null)
            {
                newNode.Next = newNode;
                newNode.Prev = newNode;
                this.head = newNode;
            }
            else
            {
                Node<T> tail = this.head.Prev;
                newNode.Next = this.head;
                newNode.Prev = tail;

                //cap nhat head va tail
                tail.Next = newNode;// chinh sua field cua tail thi field do cua head cung doi() //giong nhu delete a thi b van con nhung cac field cua b bi xoa
                this.head.Prev= newNode;//newNode tro than tail 

                //ko doi chuc vu vi tail la con tro tam
            }
        }

        public void delFirst()
        {
            if (this.head == null)//emp
		        return;
	        else if (this.head == this.head.Prev)//1 element
		        this.head = null;
	        else
	        {
		        //DOI
		        Node<T> tail = this.head.Prev;
		        Node<T> delNode = this.head;
		        this.head = this.head.Next;
		        this.head.Prev = tail;
		        tail.Next = this.head;//nho cap nhat tail next

		        //XOA 
		        delNode = null;
	        }
        }

        public void delLast()
        {
            if (this.head == null)//emp
		        return;
	        else if (this.head == this.head.Prev)//1 element
		        this.head = null;
	        else
	        {
		        //DOI
		        Node<T> tail = this.head.Prev;
		        Node<T> newTail = tail.Prev;
		        Node<T> delNode = tail;

		        //cap nhat head va tail moi
		        this.head.Prev = newTail;
		        newTail.Next = this.head;

		        //XOA 
		        delNode = null;
	        }
        }

        public void delNode(Node<T> del)
        {
            if (del == null)
                return;
            else if (del == this.head)
                this.delFirst();
            else if (del == this.head.Prev)
                this.delLast();
            else
            {
                //giong voi cua DoublyLinkedList
                del.Prev.Next= del.Next;
                del.Next.Prev = del.Prev;
                del = null;
            }
        }

        public void delAt(int idx)
        {
            //TODO DUA VAO IDX DE DE  TU HEAD/ TAIL
            if (idx < 0 || idx >= this.Length())
                return;
            int len = 0; Node<T> temp = this.head;
            if (temp == null)//emp
                return;

            while (len < idx)
            {
                temp = temp.Next;
                len++;
            }
            delNode(temp);
            //TODO delNode ne de private
        }

        public int Length()
        {
            int dem = 0; Node<T> temp = this.head;
            if (temp == null)
                return dem;
            do
            {
                dem++;
                temp = temp.Next;
            } while (temp != this.head);
            return dem;
        }

        //kien thuc moi
        private Node<T> getNode(int idx)
        {
            if (idx >= 0 && idx < Length())
            {
                Node<T> temp = this.head;
                int count = 0;
                while (count != idx)
                {
                    temp = temp.Next;
                    count++;
                }
                return temp;
            }
            else
                return null;
		        //return default(T);
            //T co the la non-nullable type nen tra ve default
        }

        /* indexer: https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/indexers/using-indexers 
                    https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/properties */
        public Node<T> this[int index]
        {
            get { return getNode(index); }
            //error: set { this[index] = value; }
        }
    }
}
