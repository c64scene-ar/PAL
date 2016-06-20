Document
  = _ body:Body _ { return body }

Body
  = name:RoomNameHeader _
    desc:RoomDescription _
    things:ThingsBlock? _
    exits:ExitsBlock? _
    {
      return {
        type: 'room',
        name: name,
        description: desc,
        things: things,
        exits: exits
      }
    }

RoomHeader
  = 'RANCHO' LF chars:'='+ &{ return chars.length === 6 } LF?

RoomNameHeader
  = 'KE? ' name:RoomName '!'
    { return name.toLowerCase() }

RoomName
  = chars:[A-Z_]+
    { return text() }

RoomDescription
  =  desc:(!EndRoomDescription c:. { return c })* EndRoomDescription
    { return desc.join('').trim() }

EndRoomDescription
  = '---' '-'* LF?

ThingsBlock
  = 'KOSAS?' LF first:Thing rest:(',' S* t:Thing { return t })*
    { return [first].concat(rest) }

Thing
  = [a-z ]+
    { return text() }

ExitsBlock
  = 'RAJEMO!' LF first:ExitPair rest:(LF e:ExitPair { return e })
    {
      return [first].concat(rest)
    }

ExitPair
  = dir:DirectionName ':' S* name:RoomName
    { return { type: 'exit', direction: dir, room: name } }

DirectionName
  = 'norte'i / 'sur'i / 'este'i / 'oeste'i / 'arriba'i

_ 'Whitespace' = [ \t\r\n]*
S 'Space' = ' '
LF = '\n' / '\r' '\n'?
