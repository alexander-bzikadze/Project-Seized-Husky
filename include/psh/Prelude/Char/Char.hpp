#pragma once

template <char s>
struct cchar {
	constexpr static char val = s;
};

using cc  = cchar< ' ' >;
using ccEM = cchar< '!' >; // !
using ccDQ = cchar< '\"' >; // "
using ccSH = cchar< '#' >; // #
using cc$ = cchar< '$' >;
using ccPE = cchar< '%' >; // %
using ccAN = cchar< '&' >; // &
using ccSQ = cchar< '\'' >; // '
using ccBL = cchar< '(' >; // (
using ccBR = cchar< ')' >; // )
using ccST = cchar< '*' >; // *
using ccPL = cchar< '+' >; // +
using ccCO = cchar< ',' >; // ,
using ccMI = cchar< '-' >; // -
using ccDO = cchar< '.' >; // .
using ccSL = cchar< '/' >; // /
using cc0 = cchar< '0' >;
using cc1 = cchar< '1' >;
using cc2 = cchar< '2' >;
using cc3 = cchar< '3' >;
using cc4 = cchar< '4' >;
using cc5 = cchar< '5' >;
using cc6 = cchar< '6' >;
using cc7 = cchar< '7' >;
using cc8 = cchar< '8' >;
using cc9 = cchar< '9' >;
using ccCL = cchar< ':' >; // :
using ccSE = cchar< ';' >; // ;
using ccLT = cchar< '<' >; // <
using ccEQ = cchar< '=' >; // =
using ccGT = cchar< '>' >; // >
using ccQM = cchar< '?' >; // ?
using ccDG = cchar< '@' >; // @
using ccA = cchar< 'A' >;
using ccB = cchar< 'B' >;
using ccC = cchar< 'C' >;
using ccD = cchar< 'D' >;
using ccE = cchar< 'E' >;
using ccF = cchar< 'F' >;
using ccG = cchar< 'G' >;
using ccH = cchar< 'H' >;
using ccI = cchar< 'I' >;
using ccJ = cchar< 'J' >;
using ccK = cchar< 'K' >;
using ccL = cchar< 'L' >;
using ccM = cchar< 'M' >;
using ccN = cchar< 'N' >;
using ccO = cchar< 'O' >;
using ccP = cchar< 'P' >;
using ccQ = cchar< 'Q' >;
using ccR = cchar< 'R' >;
using ccS = cchar< 'S' >;
using ccT = cchar< 'T' >;
using ccU = cchar< 'U' >;
using ccV = cchar< 'V' >;
using ccW = cchar< 'W' >;
using ccX = cchar< 'X' >;
using ccY = cchar< 'Y' >;
using ccZ = cchar< 'Z' >;
using ccSBL = cchar< '[' >; // [
using ccBS = cchar< '\\' >; // \/
using ccSBR = cchar< ']' >; // ]
using ccCF = cchar< '^' >; // ^
using cc_ = cchar< '_' >;
using ccGR = cchar< '`' >; // `
using cca = cchar< 'a' >;
using ccb = cchar< 'b' >;
using ccc = cchar< 'c' >;
using ccd = cchar< 'd' >;
using cce = cchar< 'e' >;
using ccf = cchar< 'f' >;
using ccg = cchar< 'g' >;
using cch = cchar< 'h' >;
using cci = cchar< 'i' >;
using ccj = cchar< 'j' >;
using cck = cchar< 'k' >;
using ccl = cchar< 'l' >;
using ccm = cchar< 'm' >;
using ccn = cchar< 'n' >;
using cco = cchar< 'o' >;
using ccp = cchar< 'p' >;
using ccq = cchar< 'q' >;
using ccr = cchar< 'r' >;
using ccs = cchar< 's' >;
using cct = cchar< 't' >;
using ccu = cchar< 'u' >;
using ccv = cchar< 'v' >;
using ccw = cchar< 'w' >;
using ccx = cchar< 'x' >;
using ccy = cchar< 'y' >;
using ccz = cchar< 'z' >;
using ccCBL = cchar< '{' >; // {
using ccVB = cchar< '|' >; // |
using ccCBR = cchar< '}' >; // }
using ccTL = cchar< '~' >; // ~
