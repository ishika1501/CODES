


//Inorder is Necesssary for the binary tree ti be unique :

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        if(( a == 2 && b != 2) || (a !=2 && b==2) ) return true;
        return false;
    }
};