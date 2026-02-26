class Solution 
{
    public static int[] twoSum(int[] nums, int target) 
    {
        int[] output;
        for(int i=0;i<nums.length;i++)
        {
            int sum=0;
            for(int j=i;j<nums.length;j++)
            {
                sum=sum+nums[j];
                if(sum==target)
                {
                    int c=0;
                    output=new int[j-i+1];
                    System.out.print("[");
                    for(int k=i;k<=j;k++)
                    {
                        System.out.print(k+",");
                        nums[c++]=k;
                    }
                    System.out.println("]");
                    break;
                }

                if(sum>target)
                    break;
            }
        }
        return nums;
    }
    public static void main(String[] args) {
        int a[]={3,3};
        int t=6;
        int b[]= new int[5];
        b=twoSum(a,t);
    }
}
