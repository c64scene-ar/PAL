Document
  = _ body:Body+ _ { return body }

Body
  = object_name:ObjectName _ "{" _ 
        object_desc:ObjectDescription _
        object_items:ObjectItems _
        object_exits:ObjectExits _
      "}" _
    
    {
      return {
          name: object_name,
            desc: object_desc,
            items: object_items,
            exits: object_exits
        }
    }
    
    
ObjectName
  = _ "DONDE?"_ object_name:$text "!" 
    { return object_name.toLowerCase() }
     
ObjectDescription
  = "DISE" _ object_desc:$multi_text _  
    { return object_desc }

ObjectItems
  = "KOSAS?" _ "{" _ object_items:Item+ _ "}"
    { return object_items }

ObjectExits
  = "LAGORRA?" _ "{" _ object_exits:Exit+ _ "}" 
    { return object_exits }
    
Exit
  = exit:$text _ "{" _ room:$text _ "}" _
    { return { exit: exit, room: room } }

Item
  = ["] item_name:$text ["] _ "{" 
      _ item_desc:ObjectDescription _ 
        _ item_actions:ItemAction*  _
        "}" _
    {
      return {
          item: item_name,
            desc: item_desc,
            actions: item_actions
        }
    }
        
ItemAction
  = item_action_verb:$text _ "@" _
      "{" 
          _ item_action_desc:ObjectDescription _
        "}" _ 
    { 
      return {
        
        verb: item_action_verb,
        desc: item_action_desc
        }
    }
text
  = chars:[A-Za-z_ ]+
    { return chars }
    
multi_text
  = _ "{" txt:(!"}" [a-zA-Z_\r\n \."\?,]+) _ "}" 
    { return txt }

comment
 = "/*" (!"*/" .)* "*/"

_ 'Whitespace' = [ \t\r\n]*
S 'Space' = ' '
LF = '\n' / '\r' '\n'?
