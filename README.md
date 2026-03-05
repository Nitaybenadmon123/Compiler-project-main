# פרויקט קומפיילר - חלק 3 (עדכני)

## תיאור כללי
פרויקט זה מממש **קומפיילר מלא** לשפת תכנות בהגדרה עצמית, המורכב משלושה חלקים עיקריים:
- **חלק 1**: ניתוח לקסיקלי (Lexical Analysis)
- **חלק 2**: ניתוח תחבירי (Syntax Analysis) ובניית עץ תחביר מופשט (AST)
- **חלק 3**: ניתוח סמנטי (Semantic Analysis) ויצירת קוד ביניים (Three-Address Code) - **החלק העדכני**

הקומפיילר כתוב בשפת C ומשתמש בכלי Flex ו-Bison ליצירת הסורק והפרסר.

---

## תכונות השפה

### טיפוסי נתונים נתמכים
- **int** - מספרים שלמים
- **real** - מספרים ממשיים
- **char** - תווים בודדים
- **bool** - ערכים בוליאניים (true/false)
- **string** - מחרוזות
- **מצביעים**: `int*`, `char*`, `real*`
- **null** - ערך ריק למצביעים

### מבני בקרה
- **if/elif/else** - תנאי
- **while** - לולאה עם תנאי מוקדם
- **for** - לולאה מבוקרת
- **do-while** - לולאה עם תנאי מאוחר

### פונקציות
- הגדרת פונקציות עם פרמטרים וטיפוס החזר
- פונקציות מקוננות (Nested Functions)
- קריאות לפונקציות
- החזרת ערכים

### אופרטורים
- **חשבוניים**: `+`, `-`, `*`, `/`, `&` (כתובת)
- **השוואה**: `==`, `!=`, `>`, `>=`, `<`, `<=`
- **לוגיים**: `and`, `or`, `not`
- **השמה**: `=`

### הערות
- הערות רב-שורתיות: `#-> ... <-#`

---

## מבנה הפרויקט

```
Projectpart3_Updated/
│
├── scanner.l              # הגדרת הסורק הלקסיקלי (Flex)
├── parser.y               # הגדרת הפרסר התחבירי (Bison)
│
├── ast.h / ast.c          # מימוש עץ התחביר המופשט (AST)
├── symbol_table.h / symbol_table.c  # טבלת סמלים וניתוח סמנטי
├── three_address_code.h / three_address_code.c  # יצירת קוד ביניים (3AC)
│
├── compiler               # הקובץ ההרצה של הקומפיילר
├── text.txt               # קובץ דוגמה לקוד מקור
│
└── קבצים שנוצרו אוטומטית:
    ├── lex.yy.c           # סורק שנוצר מ-Flex
    ├── parser.tab.c/h     # פרסר שנוצר מ-Bison
    └── y.tab.c/h          # קבצים נוספים שנוצרו
```

---

## הידור והרצה

### דרישות מקדימות
- **Flex** (GNU Flex) - ליצירת הסורק הלקסיקלי
- **Bison** (GNU Bison) - ליצירת הפרסר התחבירי
- **GCC** או כל קומפיילר C אחר

### צעדי הידור

1. **יצירת הסורק הלקסיקלי**:
```bash
flex scanner.l
```

2. **יצירת הפרסר התחבירי**:
```bash
bison -d parser.y
```

3. **קימפול כל הקבצים**:
```bash
gcc -o compiler parser.tab.c lex.yy.c ast.c symbol_table.c three_address_code.c -lfl
```

**או בפקודה אחת**:
```bash
flex scanner.l && bison -d parser.y && gcc -o compiler parser.tab.c lex.yy.c ast.c symbol_table.c three_address_code.c -lfl
```

### הרצת הקומפיילר
```bash
./compiler < text.txt
```

או בסביבת Windows:
```powershell
.\compiler.exe < text.txt
```

---

## דוגמאות תחביר

### הגדרת פונקציה בסיסית
```
def add(par1 int:x; par2 int:y) : returns int
begin
    return x + y;
end
```

### הגדרת פונקציה עם משתנים מקומיים
```
def factorial(par1 int:n) : returns int
var
    type int: result;
begin
    if (n == 0) or (n == 1)
        result = 1;
    else
        result = n * call factorial(n-1);
    end
    return result;
end
```

### פונקציה עם בלוקים מקוננים
```
def example(par1 int:a; par2 int:b) : returns bool
var 
    type bool: res;
begin
    var  
        type char: x, y;
        type int: z;
    begin
        x = 'A';
        y = 'B';
        z = a + b;
        res = (z > 0);
    end
    return res;
end
```

### מבני בקרה
```
def test_conditions(par1 int:x) : returns int
var
    type int: result;
begin
    # תנאי if-elif-else
    if x > 10
        result = 1;
    elif x > 5
        result = 2;
    else
        result = 3;
    end
    
    # לולאת while
    while x > 0
        x = x - 1;
    end
    
    # לולאת for
    for (x = 0; x < 10; x = x + 1)
        result = result + x;
    end
    
    return result;
end
```

### עבודה עם מצביעים
```
def pointer_example(par1 int*:ptr) : returns int
var
    type int: value;
begin
    value = 42;
    ptr = &value;
    return value;
end
```

---

## תהליך הקימפול

### חלק 1: ניתוח לקסיקלי (Lexical Analysis)
- **כלי**: Flex (`scanner.l`)
- **תפקיד**: פירוק קוד המקור ל-Tokens (מילות מפתח, מזהים, מספרים, אופרטורים וכו')
- **פלט**: רצף של Tokens

### חלק 2: ניתוח תחבירי (Syntax Analysis)
- **כלי**: Bison (`parser.y`)
- **תפקיד**: בדיקת תקינות התחביר לפי הדקדוק ובניית עץ תחביר מופשט (AST)
- **פלט**: AST המייצג את מבנה התוכנית

### חלק 3: ניתוח סמנטי ויצירת קוד ביניים (עדכני)
- **רכיבים**:
  - **Symbol Table** (`symbol_table.c/h`) - טבלת סמלים לניהול משתנים, פונקציות ו-Scopes
  - **Semantic Checks** - בדיקות סמנטיות:
    - התאמת טיפוסים (Type Checking)
    - בדיקת הצהרות כפולות
    - בדיקת שימוש במשתנים לא מוצהרים
    - בדיקת התאמת פרמטרים בקריאות לפונקציות
    - בדיקת טיפוס ערך החזר
  - **Three-Address Code Generator** (`three_address_code.c/h`) - יצירת קוד ביניים

#### סוגי הוראות קוד ביניים (3AC)
```
TAC_ASSIGN      - השמה פשוטה: x = y
TAC_BINARY_OP   - פעולה בינארית: x = y op z
TAC_UNARY_OP    - פעולה אונרית: x = op y
TAC_COPY        - העתקה: x = y
TAC_GOTO        - קפיצה ללא תנאי: goto L
TAC_IF_GOTO     - קפיצה מותנית: if x relop y goto L
TAC_LABEL       - תווית: L:
TAC_PARAM       - פרמטר: param x
TAC_CALL        - קריאה לפונקציה: x = call f
TAC_RETURN      - החזרת ערך: return x
TAC_BEGIN_FUNC  - התחלת פונקציה: BeginFunc size
TAC_END_FUNC    - סיום פונקציה: EndFunc
```

---

## פלטים

### עץ התחביר המופשט (AST)
הקומפיילר מדפיס את ה-AST המלא של התוכנית, המציג את מבנה התוכנית היררכית.

### טבלת הסמלים (Symbol Tables)
הצגה של כל ה-Scopes והסמלים שהוגדרו בהם:
- משתנים עם הטיפוסים שלהם
- פונקציות עם הטיפוסים, מספר הפרמטרים וטיפוסי הפרמטרים

### קוד ביניים (Three-Address Code)
רשימת הוראות 3AC המייצגות את לוגיקת התוכנית בצורה פשוטה ונוחה לייעול ולתרגום לקוד מכונה.

### הודעות שגיאה
- **Lexical Errors** - תווים לא חוקיים
- **Syntax Errors** - שגיאות תחביר
- **Semantic Errors** - שגיאות סמנטיות (טיפוסים לא תואמים, משתנים לא מוגדרים וכו')

---

## דוגמת קוד וההרצה

### קובץ `text.txt`:
```
def foo1(par1 int:a; par2 int:b; par3 int:c; par4 char:c1) : returns bool
var 
    type bool: res;
begin
    var  
        type char: x, b;
        type int: y;
    begin
        b = '&';
        a = (y*7)/a-y;
        res = (b==c1) and (y>a);
    end
    return res;
end
```

הרצת הקומפיילר תציג:
1. ✅ עץ AST
2. ✅ טבלאות סמלים לכל Scope
3. ✅ קוד 3AC שנוצר
4. ❌ או הודעות שגיאה במקרה של בעיות

---

## תכונות מתקדמות

### פונקציות מקוננות
השפה תומכת בהגדרת פונקציות בתוך פונקציות אחרות:
```
def outer(par1 int:x) : returns int
begin
    def inner(par1 int:y) : returns int
    begin
        return y * 2;
    end
    
    return call inner(x);
end
```

### ניהול Scopes
- כל בלוק (`begin...end`) יוצר Scope חדש
- משתנים מקומיים נשמרים בטבלת סמלים של ה-Scope שלהם
- חיפוש משתנים מתבצע מה-Scope הנוכחי כלפי מעלה

### בדיקות טיפוסים
- בדיקת התאמת טיפוסים בפעולות חשבון
- בדיקת טיפוס תנאים בוליאניים במבני בקרה
- בדיקת התאמת טיפוסי פרמטרים בקריאות לפונקציות
- בדיקת טיפוס ערך החזר

---

## מחבר
פרויקט זה פותח כחלק מקורס עקרונות קומפילציה.

**גרסה עדכנית**: חלק 3 - Projectpart3_Updated

**תאריך**: מרץ 2026

---

## רישיון
פרויקט אקדמי לצורכי לימוד בלבד.
