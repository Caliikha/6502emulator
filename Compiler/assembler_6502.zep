@set RAM.size = 65535
@set STACK.size = 256

.<start>

var number  , $92;
    LDA_im  , number;
    LDA_ZP  , $03;
    LDA_im  , $41;
    LDA_ZPX , $03;
    LDA_im  , $31;

.<end>

