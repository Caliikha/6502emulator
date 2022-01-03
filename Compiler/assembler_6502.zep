@set RAM.size = 65535
@set STACK.size = 256

.<start>

    LDA_im, $42;
    LDA_ZP, $03;
    LDA_im, $41;
    LDA_ZPX, $03;

.<end>

