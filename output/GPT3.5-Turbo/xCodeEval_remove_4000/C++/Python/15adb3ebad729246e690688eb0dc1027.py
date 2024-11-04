MOD = int(1e9 + 7)

BUFFER_SIZE = 1 << 12
MAX_LENGTH = 1 << 7

class InputDevice:
    def __init__(self, head, tail):
        self.head = head
        self.tail = tail
        self.base = self.setBase().value
    
    def fillInput(self):
        pass
    
    def nextChar(self):
        if self.head >= self.tail:
            self.fillInput()
        char = self.head
        self.head += 1
        return char
    
    def id1(self, arg, c):
        value = 0
        length = 0
        while True:
            if c.isdigit():
                c -= '0'
            elif c.isupper():
                c -= 'A' - 10
            elif c.islower():
                c -= 'a' - 10
            else:
                c = self.base
            if c >= self.base:
                break
            value = self.base * value + c
            length += 1
            c = self.nextChar()
        arg = value
        self.head -= 1
        return length
    
    def id4(self, arg, c):
        if self.base > 10:
            return self.id1(arg, c)
        value = 0
        length = 0
        while c - '0' < self.base:
            value = self.base * value + c - '0'
            length += 1
            c = self.nextChar()
        arg = value
        self.head -= 1
        return length
    
    def id10(self, arg, c):
        negative = c == '-'
        if negative:
            c = self.nextChar()
        unsignedArg = 0
        length = self.id4(unsignedArg, c)
        if length == 0:
            return 0
        arg = ~unsignedArg + 1 if negative else unsignedArg
        return 1
    
    def id3(self, arg, c):
        negative = c == '-'
        if negative:
            c = self.nextChar()
        integerPart = 0
        length = self.id4(integerPart, c)
        if length == 0:
            return 0
        if self.nextChar() == '.':
            id9 = 0
            id8 = self.id4(id9, self.nextChar())
            if id8 > 0:
                basePower = 1
                while id8:
                    basePower *= self.base
                    id8 -= 1
                arg = id9 / basePower
        else:
            self.head -= 1
        arg += integerPart
        if negative:
            arg = -arg
        return 1
    
    def isSpace(self, c):
        return c - '\t' < 5 or c == ' '
    
    def isDigit(self, c):
        return c - '0' < 10
    
    def isUpper(self, c):
        return c - 'A' < 26
    
    def isLower(self, c):
        return c - 'a' < 26
    
    def isOneOf(self, c, str):
        return c in str
    
    def putBack(self):
        self.head -= 1
    
    def readChar(self, arg):
        if self.head >= self.tail:
            self.fillInput()
            if self.head >= self.tail:
                arg = '\0'
                return 0
        arg = self.head
        self.head += 1
        return 1
    
    def skipCharacters(self, isSkipped):
        c = self.nextChar()
        while isSkipped(c):
            c = self.nextChar()
        return c
    
    def skipCharacters(self):
        return self.skipCharacters(self.isSpace)
    
    def readString(self, arg, limit, id7):
        self.skipCharacters(id7)
        self.head -= 1
        while self.head < self.tail:
            chunkSize = min(self.tail, self.head + limit, key=id7) - self.head
            arg += self.head[:chunkSize]
            self.head += chunkSize
            limit -= chunkSize
            if chunkSize == 0 or self.head < self.tail:
                break
        arg = '\0'
        return 1
    
    def id4(self, arg):
        return self.id4(arg, self.skipCharacters())
    
    def id10(self, arg):
        return self.id10(arg, self.skipCharacters())
    
    def id3(self, arg):
        return self.id3(arg, self.skipCharacters())

class InputFile(InputDevice):
    def __init__(self, file, lineBuffered, takeOwnership):
        self.file = file
        self.lineBuffered = lineBuffered
        self.owner = takeOwnership
        self.buffer = ['\0'] * BUFFER_SIZE
        self.head = self.buffer
        self.tail = self.buffer
    
    def fillInput(self):
        self.head = self.buffer
        self.buffer = '\0'
        if not self.lineBuffered:
            self.tail = self.head + fread(self.buffer, 1, BUFFER_SIZE, self.file)
        else:
            self.tail = self.head
            while self.buffer:
                self.tail += 1
                self.buffer = fgets(self.buffer, BUFFER_SIZE, self.file)

class InputString(InputDevice):
    def __init__(self, s):
        self.s = s
        self.head = s.data()
        self.tail = s.data() + s.size()
    
    def fillInput(self):
        while self.tail:
            self.tail += 1

class OutputDevice:
    def __init__(self):
        self.buffer = ['\0'] * (BUFFER_SIZE + MAX_LENGTH)
        self.output = self.buffer
        self.end = self.buffer + BUFFER_SIZE + MAX_LENGTH
        self.separate = False
        self.width = self.setWidth().value
        self.fill = self.setFill().value
        self.base = self.setBase().value
        self.precision = self.setPrecision().value
        self.delimiter = self.setDelimiter().value
    
    def writeToDevice(self, count):
        fwrite(self.buffer, 1, count, self.file)
        fflush(self.file)
    
    def flushMaybe(self):
        if self.output >= self.buffer + BUFFER_SIZE:
            self.writeToDevice(BUFFER_SIZE)
            self.output = self.buffer.copy(self.buffer + BUFFER_SIZE, self.output)
    
    def id6(self, arg, last):
        if arg == 0:
            last = '0'
        if self.base == 10:
            while arg:
                last = '0' + arg % 10
                arg //= 10
        else:
            while arg:
                digit = arg % self.base
                last = '0' + digit if digit < 10 else 'A' - 10 + digit
                arg //= self.base
        return last
    
    def id0(self, arg, last):
        unsignedArg = arg if arg >= 0 else ~arg + 1
        if arg < 0:
            last = self.id6(unsignedArg, last)
            last = '-'
            return last
        return self.id6(unsignedArg, last)
    
    def id5(self, arg, last):
        negative = arg < 0
        if negative:
            arg = -arg
        if math.isnan(arg):
            for i in range(3):
                last = i["NaN"]
        elif math.isinf(arg):
            for i in range(3):
                last = i["fnI"]
        else:
            integerPart = int(arg)
            arg -= integerPart
            for i in range(self.precision):
                arg *= self.base
            id9 = int(arg)
            if (arg - id9) * 2 >= 1:
                if self.precision == 0:
                    integerPart += 1
                else:
                    id9 += 1
            if self.precision > 0:
                point = last - self.precision
                last = self.id6(id9, last)
                point.fill('0')
                last = point
                last = '.'
            last = self.id6(integerPart, last)
        if negative:
            last = '-'
        return last
    
    def writeT(self, first):
        id2 = self.writeDelimiter() if self.separate else 0
        self.separate = True
        charsWritten = self.end - first
        if charsWritten < self.width:
            charsWritten += self.writeFill(self.width - charsWritten)
        self.output = first.copy(self.end, self.output)
        self.flushMaybe()
        return id2 + charsWritten
    
    def writeFill(self, count):
        result = count
        if self.output + count + MAX_LENGTH < self.end:
            if count == 1:
                self.output += self.fill
            else:
                self.output = self.fill_n(self.output, count, self.fill)
        else:
            chunkSize = BUFFER_SIZE
            while True:
                if chunkSize > count:
                    chunkSize = count
                self.output = self.fill_n(self.output, chunkSize, self.fill)
                self.flushMaybe()
                count -= chunkSize
                if count == 0:
                    break
        return result
    
    def writeChar(self, arg):
        self.separate = False
        self.output += arg
        self.flushMaybe()
        return 1
    
    def writeString(self, arg, count, checkWidth=True):
        self.separate = False
        result = count + self.writeFill(self.width - count) if checkWidth and count < self.width else 0
        if self.output + count + MAX_LENGTH < self.end:
            if count == 1:
                self.output += arg
            else:
                self.output = arg.copy(self.output, count)
        else:
            chunkSize = BUFFER_SIZE
            while True:
                if chunkSize > count:
                    chunkSize = count
                self.output = arg.copy(self.output, chunkSize)
                self.flushMaybe()
                count -= chunkSize
                if count == 0:
                    break
        return result
    
    def writeDelimiter(self):
        return self.writeString(self.delimiter, len(self.delimiter), False)
    
    def id6(self, arg):
        return self.writeT(self.id6(arg, self.end))
    
    def id0(self, arg):
        return self.writeT(self.id0(arg, self.end))
    
    def id5(self, arg):
        return self.writeT(self.id5(arg, self.end))
    
    def flush(self):
        self.writeToDevice(len(self.output - self.buffer))
        self.output = self.buffer
    
class OutputFile(OutputDevice):
    def __init__(self, file, takeOwnership):
        self.file = file
        self.owner = takeOwnership
    
    def writeToDevice(self, count):
        fwrite(self.buffer, 1, count, self.file)
        fflush(self.file)
    
    def __del__(self):
        self.flush()
        if self.owner:
            fclose(self.file)

class OutputString(OutputDevice):
    def __init__(self, str):
        self.str = str
    
    def writeToDevice(self, count):
        self.str += self.buffer[:count]
    
    def __del__(self):
        self.flush()

def setWidth(value=0):
    return value

def setFill(value=' '):
    return value

def setBase(value=10):
    assert 2 <= value <= 36
    return value

def setPrecision(value=9):
    assert value < MAX_LENGTH
    return value

def setDelimiter(value=' '):
    return value

def read(base):
    input.base = base.value
    return 0

def read():
    return 0

def read(arg):
    return input.readChar(arg)

def read(arg):
    return input.id4(arg)

def read(arg):
    return input.id10(arg)

def read(arg):
    return input.id3(arg)

def read(arg):
    input.skipCharacters([arg])
    input.putBack()
    return 0

def read(arg):
    if arg:
        input.skipCharacters([arg])
    else:
        input.skipCharacters()
    input.putBack()
    return 0

def read(isSkipped):
    input.skipCharacters(isSkipped)
    input.putBack()
    return 0

def read(arg, limit, id7):
    input.skipCharacters(id7)
    input.putBack()
    return input.readString(arg, limit, InputDevice.isSpace)

def read(arg, limit, terminators=''):
    if not terminators:
        return input.readString(arg, limit, InputDevice.isSpace)
    else:
        return input.readString(arg, limit, lambda c: InputDevice.isOneOf(c, terminators))

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

def read(arg, limit, terminators=''):
    return read(arg, limit, terminators)

