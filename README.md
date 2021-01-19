# Infix-to-Postfix-convertion-using-stack
An infix expression is the one in which the operator is used in between operands(binary operators).In postfix the operator is placed after the operands.
Tere are some rules to convert an infix expression to postfix expression.
Rules:
Read the infix expression character by character.
A.If the character is an alphanumerical character simply add it to the postfix expression.
B.Else(the character is an operator)
    1.If it is other than '(' and ')'
         a.If the precedence of the operator is higher than that of top of stack , then simply push it to the stack.
         b.If the precedence is less or equal ,then pop out from stack and add the popped character (operator) to postfix expression untill you counter an operator of lesser precedence and then push the new operator to stack.
    2.If it is '(' simply push to the stack.
    3.If it is ')' pop out from the stack and add  the popped character (operator) to the postfix expression untill you encounter an '(' ,then pop out '(' only
C.At last , if there is any operator left in stack pop it and add to postfix expression.    
    eg. Convert  "v*w+x/y^(z+5)" to postfix :
      
 push value     stack             pop value      add to postfix exp.              Final postfix expression
                                                   v         //@ Rule - A                   v
    *             *                                                                         v
                  *                                w         //@ Rule - A                   vw
                                     *             *          //@Rule - B.1.b               vw*
    +             +                                                                         vw*
                                                   x          //@ Rule - A                  vw*x
    /             +,/                                         //@Rule - B.1.a               vw*xy
                                                   y          //@ Rule - A                  vw*xy
    ^             +,/,^                                       //@Rule-B.1.a                 vw*xy
    (             +,/,^,(                                     //@Rule-B.2                   vw*xy
                                                   z                                        vw*xyz
    +             +,/,^,(,+                                   //@Rule-B.1.a                 vw*xyz
                                                   5                                        vw*xyz5
                  +,/,^,(             +            +          //@Rule -B.3                  vw*xyz5+
                  +,/,^               (                       //@Rule -B.3                  vw*xyz5+
                                      ^            ^          //@Rule- C                    vw*xyz5+^
                                      /            /          //@Rule- C                    vw*xyz5+^/
                                      +            +          //@Rule- C                    vw*xyz5+^/+
                                     
