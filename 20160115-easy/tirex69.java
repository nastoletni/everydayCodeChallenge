import java.util.Scanner;

/*
  @author: TiREX69
  
  Spacje moga sie nie zgadzac, bo pisalem to w http://www.tutorialspoint.com/compile_java_online.php
*/

public class HelloWorld{

     public static void main(String []args){
         System.out.print("Podaj liczbe do przekonwertowania: ");
         Scanner scanner = new Scanner(System.in);
         String text = scanner.next();
         scanner.close();
         
         Integer number = parseInteger(text);
         if (number != null)
         {
             if (number < 1 || number > 4999)
             {
                 System.out.println("Nieprawidlowy zakres liczby <1 lub >4999");
                 System.exit(1);
             }
             String roman = RomanConverter.toRoman(number);
             if (roman != null)
             {
                 System.out.println(roman);
                 System.exit(0);
             }
         }
         number = RomanConverter.fromRoman(text);
         if (number == null)
         {
             System.out.println("Nieprawidlowy format rzymskiej liczby");
             System.exit(1);
         }
         System.out.println(number);
         System.exit(0);
     }
     
     private static Integer parseInteger(String text)
     {
         try {
             return Integer.parseInt(text);
         } catch (NumberFormatException e) {
             return null;
         }
     }
     
     static class RomanConverter
     {
        private static int[]  numbers = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        private static String[] letters = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
         
         public static String toRoman(final int decimal)
         {
             StringBuilder roman = new StringBuilder();
             int end = decimal;
             for (int i = 0; i < numbers.length; i++) 
             {
                 int number = numbers[i];
                 while (end >= number) 
                 {
                     roman.append(letters[i]);
                     end -= number;
                }
            }
            return roman.toString();
         }
         
         public static Integer fromRoman(final String roman)
         {
             if (roman == null || roman.isEmpty())
             {
                 return null;
             }
             Integer decimal = 0;
             int lastInt = 0;
             
             char[] chars = roman.toCharArray();
             for (int i = 0; i < chars.length; i++)
             {
                 char c = chars[i];
                 switch (c)
                 {
                    case 'M':
                        decimal = getDecimal(1000, lastInt, decimal);
                        lastInt = 1000;
                        break;
                    case 'D':
                        decimal = getDecimal(500, lastInt, decimal);
                        lastInt = 500;
                        break;
                    case 'C':
                        decimal = getDecimal(100, lastInt, decimal);
                        lastInt = 100;
                        break;
                    case 'L':
                        decimal = getDecimal(50, lastInt, decimal);
                        lastInt = 50;
                        break;
                    case 'X':
                        decimal = getDecimal(10, lastInt, decimal);
                        lastInt = 10;
                        break;
                    case 'V':
                        decimal = getDecimal(5, lastInt, decimal);
                        lastInt = 5;
                        break;
                    case 'I':
                        decimal = getDecimal(1, lastInt, decimal);
                        lastInt = 1;
                        break;
                    default:
                        return null;
                 }
                 if (decimal == null)
                 {
                     return null;
                 }
             }
             return decimal;
         }
         
         private static Integer getDecimal(final int currentInt, final int lastInt, final int input)
         {
             int output = input;
             if (lastInt > 0 && currentInt > lastInt)
             {
                 if (currentInt >= 1 && currentInt <= 10)
                 {
                     if (lastInt != 1 && lastInt != 5)
                     {
                         return null;
                     }
                 }
                 else if (currentInt > 10 && currentInt <= 100)
                 {
                     if (lastInt != 10 && lastInt != 50)
                     {
                         return null;
                     }
                 }
                 else if (currentInt > 100 && currentInt <= 1000)
                 {
                     if (lastInt != 100 && lastInt != 500)
                     {
                         return null;
                     }
                 }
                 output += currentInt - 2 * lastInt;
             }
             else
             {
                 output += currentInt;
             }
             return output;
         }
     }
}
