Merge Overlapping Intervals :    // example=> [1,4],[2,6],[8,11],[9,10],[11,15]
								//	output=> [1,6],[8,15]
/* * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };*/


 bool comp(Interval a, Interval b)   //comparator function , for the start element of the Intervals
 {
     return a.start<b.start;
 }
 vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
 
    if(A.size()<=0)
    return A;
    
    sort(A.begin(),A.end(),comp);
    stack <Interval> s;            //stack containg struct Intervals
    vector <Interval> res;
    Interval temp;
    s.push(A[0]);                  // first Interval  from sorted Array of Intervals
    
  for(i=1;i<n;i++)					
    {
        temp = s.top();
        if(temp.end <A[i].start)  // condition of no overlapping;
           {
               s.push(A[i]);       // the next element gets pushed in stack
           }
           
        else if(temp.end< A[i].end)   // overlapping occurs (it's sorted array of Intevals)
          {
              temp.end= A[i].end;;   // upadtind the end val ;
              s.pop();				// removing the old one and replacing the new updated element
              s.push(temp);
          }
    }
      while(!s.empty())					// inserting in new  resultant Array of Intervals 
      {
          res.insert(res.begin(),s.top());
          s.pop();
      }return res;
      
      




reverse linked list:
	3 Node* pointer => curr,next,prev;
	  1.curr = head , next = NULL, prev= NULL;
	  2.while(curr!=NULL) 
	      next = curr->next
	      curr->next = prev
	      prev = curr
	      curr = next
	   3.head = prev.
	   

Detect a cylce in linked list: slow and fast  pointer  method
	1.slow =head ;fast = head;
	2.while(slow && fast && fast->next)
	      slow = slow->next
	      fast = fast->next->next
	      if(slow==fast) flag = false ,return true;

  mapping method: recursion
  	1.map<Node*, bool> cycle_check
  	2. function check(head)
  		if(head==NULL) return    // terminating condition for recursion
  		if(!cycle_check[head])
  				cycle_check[head] = true
  				check(head->next)     // recursion 
		else
			flag = true ,return   // loop exists, 

Middle in Linked List: slow and fast pointer(tortoise and  rabbit method)
	1. slow_pointer = head; fast_pointer = head;
	2. while(fast_pointer!=NULL && fast_pointer->next!=NULL)
			slow_pointer = slow_pointer->next
			fast_pointer = fast_pointer->next->next   // fast pointer travels at twice speend so by the time it reaches
	3. retur slow_pointer;												// end slow must reach mid as it travels at half speed of fast_pointer.


Reverse a linked list by k groups: recursion Solution  //eg 1->2->3->4->5  k=2
	function reverse_by_k_grp(head , k)								  //output = 2->1->4->3->5	   k=3 op = 3->2->1->4->5
			if(head==NULL || head->next == NULL)   // terminating condition  ,if n(no. of nodes)< k,return same list
				return head;

			if(node_count <k)return head;    // check in every recursion
										i=0;
			while(iteration k times && curr !=NULL) => i<k  // reverse the first k nodes
				reverse linked list function
			head->next = reverse_by_k_grp(curr,k)
			return prev;

2 Sum (hashing) :      finding the pair of two no. whose sum is a specific target no.
vector<int> Solution::twoSum(const vector<int> &A, int B) {
map<int,int> mp;
for(int i=0;i<A.size();i++)
{
    int find=B-A[i];               // find =  the counter pair of A[i]
    if(mp.count(find)) 				  // if it,s pair for the sum existes
       add it to the result
     if(mp.count(A[i])==0)      // adding A[i] in the hadh table or map and with its value as its index(not 0 basing)
       mp[A[i]]=i+1;


GetMin in a stack with O(1) run time:
   1. storing the min no. always in a variable (say min_no)and 
      creating hash function in such way that 
      whenever a even smaller no. is added in the stack
      the old min is not lost
   2. if a greater no. is added => no need to change the min_no value
       just add it in the stack
   3.If new no. < min_no : push(x) ,x<min_no
       push => 2.x - min_no;
       min_no = x;
   4. while pop() if the pop() returns not min_no => all good continue
                 if the pop() returns min_no.
                 	 pop = min_no =>(x)
                 	 and update the min_no  = as we pushed 2.x - min_no(previous)
                 	 							top = 2(min_no) - (previous min_no)
                 	 					 therefore, min_no = 2(x, current min) - top_value;





N stack in a single array:
  1. we use 3 arrays => top_stack(size N)(stores top of each stack) 
                        arr (stores all the data)
                        next_index( tell us the next available index in the arr[] as well us helps us to track the
                        	            prev index of top_stack in the arr[] while pop() )
                                       eg. initial value = [1,2,3,4...,-1]
  2. next_available_index =0 (initial to 0  as next available index is 0 .
  	 							after pushing  it takes the value from the next_index array
  	 							showing the next available index. )


  =>>
    push(stack_index , value_to insert)
       curr_index = next_available_index  // data insert at this index
       arr[curr_index] =value_to insert  
       next_available_index = next_index[curr_index]  // as the next_inex array stores the next available index 
	   next_index[curr_index] = top_stack[stack_index]  //  so that we know the prev index of that stack;
	   top_stack[stack_index] = curr_index;

	pop(stack_index)
	    curr_index = top_stack[stack_index]
	    top_stack[stack_index]= next_index[curr_index] // as it stored the prev index for the stack
	    next_index[curr_index]=next_available_index
	    next_available_index = curr_index    // as curr_index is now freed and can be overwritten 5]pk+6/7


Stock Span Problem:   //eg to find the the no. of prev days for which the price was lower than current day
  brute force method=> with incresing i traversing each day,
  					   compare every previous day (j--) till a greater price is reached .
  					   time complexity =  N^2;

  Using Stacks=>
      we see that the span is the (current day index - the index of day having greater price) 
                            it works on the idea that in a span if the n no. of days have 
                            lower prices , then for the next day , we already know the those day 
                            need not be traverseed again.


      1. stack <int > s;  array to store span of each day span[n];

       s.push(0)       //initial value for the first day index is 0;
       span[0] =1    // for the first day 
       while(s!=empty && price[s.top]<=price[i])
       	  s.pop()                          // spam  = i - the index where the price is greater than the curr day


       if(s.empty) span[i] = i+1  // gratest price of all
        else span[i]  = i-s.top()    // the index of greater price as the lesser price day index have been popped
      
      s.push(i); 
