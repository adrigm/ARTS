#ifndef BASE64_H
#define BASE64_H

extern unsigned char *php3_base64_encode(const unsigned char *, int, int *);
extern unsigned char *php3_base64_decode(const unsigned char *, int, int *);

#endif /* BASE64_H */