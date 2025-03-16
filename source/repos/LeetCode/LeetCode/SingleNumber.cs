
using System.Data;
using System.Numerics;

namespace Logic
{
    public class SingleNumber
    {
        public  int Single(int[] nums)
        {

            int result = 0;
            for (int i = 0; i<nums.Length; i++)
            {
                result ^= nums[i];
            }

            return result;
        }
        public void binarySearch(int[] nums, int n)
        {
            int l = 0, r = nums.Length - 1;

            while (l < r)
            {
                if (nums[l] == n)
                {
                    Console.WriteLine(nums[l]);
                    return;
                }
                int temp = (l+r)/2;
                if (nums[temp] > n) l = temp;

            }

        }

        public void giaiPT(int a, int b, int c)
        {
            if (b == 0)
            {
                Console.WriteLine("{0}/{1}", c, a);
                return;
            }
            else if (c == 0)
            {
                Console.WriteLine("{0}/{1}", -b, a);
                return;
            }
            else if (a == 0 && b == c)
            {
                Console.WriteLine("PT vô số nghiệm");
                return;
            }
            else if (a == 0 && b != c)
            {
                Console.WriteLine("PT vô nghiệm");
                return;
            }
            else
            {
                Console.WriteLine("{0}/{1}", (c-b), a);
            }    
        }

        public int UCLN(int a, int b)
        {
            //if (b==0)
            //    return a;
            //return UCLN(b, a%b);
            while(a!=b)
            {
                if(a > b)
                {
                    a = a - b;
                }
                else 
                {
                    b = b - a;
                }
            }

            return a;

        }

        public int BCNN(int a, int b)
        {
            return (a*b)/UCLN(a, b);
        }
           
        public void giaiPT2(int a, int b, int c)
        {
            if(a == 0)
            {
                Console.WriteLine($"x = -{c}/{b}");
                return;
            }
            int deta = (int)Math.Pow(b, 2) - 4*a*c;
            if (deta < 0)
            {
                Console.WriteLine("Phương trình vô nghiệm");
                return ;
            }
            else if(deta == 0)
            {
                Console.WriteLine($"x = -{b}/{2*a}");
                return ;
            }
            else
            {
                double x1, x2;
                x1 = (-b + Math.Sqrt(deta))/2;
                x2 = (-b - Math.Sqrt(deta))/2;

                Console.WriteLine($"x1 = {x1}, x2 = {x2}");
            }
        }

        public void example()
        {
            List<int> a = new List<int> { 1,2,-5,6,4,9};
            var b = a.OrderByDescending(x => x);

            foreach(int i in b)
            {
                Console.WriteLine(i);
            }
        }
    }

    public class SinhVien
    {
        
    }
}

