using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MusicPlayerAutoPlaylist
{
    class Node<T>
    {
        private T data;
        public T Data
        {
            get { return data; }
            set { data = value; }
        }

        Node<T> next;
        internal Node<T> Next
        {
            get { return next; }
            set { next = value; }
        }

        Node<T> prev;
        internal Node<T> Prev
        {
            get { return prev; }
            set { prev = value; }
        }



        public Node(T dat)
        {
            this.data = dat;
            this.next = null;
            this.prev = null;
        }
    }
}
