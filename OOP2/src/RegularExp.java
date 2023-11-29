import java.util.regex.*;

public class RegularExp {
    public static void main(String[] args) {
        String rollNumberRegex = "\\d{4}$";
        String sessionRegex= "\\d{4}-\\d{4}$";
        String emailRegex= "^bsse.+@iit\\.du\\.ac\\.bd$";

        Matcher validMatcher;

        // Create a Pattern object
        Pattern rollPattern = Pattern.compile(rollNumberRegex);
        Pattern sessionPattern= Pattern.compile(sessionRegex);
        Pattern emailPattern= Pattern.compile(emailRegex);

        // Test strings
        String rollNumber = "1412";
        String session = "2021-2022";
        String email = "bsse1412@iit.du.ac.bd";

        // Test valid roll number
        validMatcher = rollPattern.matcher(rollNumber);
        if (validMatcher.matches()) {
            System.out.println(rollNumber + " is a valid 4-digit roll number.");
        } else {
            System.out.println(rollNumber + " is not a valid 4-digit roll number.");
        }

        validMatcher = sessionPattern.matcher(session);
        if(validMatcher.matches()){
            System.out.println(session+" is a valid Session");
        }else{
            System.out.println(session+" is a invalid Session");
        }

        validMatcher = emailPattern.matcher(email);
        if(validMatcher.matches()){
            System.out.println(email+" is a valid Email");
        }else{
            System.out.println(email+" is a invalid Email");
        }

    }
}


