/**
 * ÕâÊÇÒ»¸ö°ü×°Àà(wrapper class)£¬°ü×°ÀàÔÚC++ÖÐÓÐµãÐ¡Ð¡µÄÓÃ´¦(»ù±¾ÉÏÃ»ÓÃ)£¬ÔÚJavaÖÐµÄÓÃ´¦¸ü´óÒ»Ð©¡£
 */

#ifndef _INT_H_  //ÕâÊÇdefine guard 
#define _INT_H_  //ÔÚCºÍC++ÖÐ£¬Í·ÎÄ¼þ¶¼Ó¦¸ÃÓÐÕâÍæÒâ 

class Int{
	
private://ÕâÊÇ·ÃÎÊ¿ØÖÆ¡ª¡ªË½ÓÐµÄ 
    int value; //ÕâÊÇÊý¾Ý³ÉÔ±£¬ÎÒÃÇ³ÆIntÊÇ»ù±¾ÀàÐÍintµÄ°ü×°Àà£¬¾ÍÊÇÒòÎªIntÀïÃæÖ»ÓÐÒ»¸öintÀàÐÍµÄÊý¾Ý³ÉÔ± 
               
public:	//ÕâÊÇ¹«ÓÐµÄ 
    //ÒÔÏÂÊÇ³ÉÔ±º¯ÊýµÄÉùÃ÷ 
    
    int getValue()const;
    
    void setValue(int v);
    
};//¼Ç×¡ÕâÀïÓÐÒ»¸ö·ÖºÅ 

#endif

