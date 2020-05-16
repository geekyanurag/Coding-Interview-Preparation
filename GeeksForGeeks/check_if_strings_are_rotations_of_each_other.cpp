// Problem is to check whether two strings are rotations of each other or not.
// e.g = s1 = mightandmagic , s2 = andmagicmight. 
// Idea is to concat the first string to itself and store the result in new string like temp = s1 + s1 and then check
// whether s2 is a substring of temp or not.
bool areRotations(string s1,string s2)
{
    if(s1.length() != s2.length())
        return false;
    
    string temp = s1 + s1;
    return (temp.find(s2) != string::npos);
}