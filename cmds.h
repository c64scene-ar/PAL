#ifndef __CMDS_H__
#define __CMDS_H__

int parse_verb(char * tok);

/* returns true if a object is detected */
int parse_object(char * tok);

int parse_cmd(char * cmd);


#endif /* __CMDS_H__ */