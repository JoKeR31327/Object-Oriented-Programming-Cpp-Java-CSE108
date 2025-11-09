/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */
public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    private Student[] waitinglist;
    int waiting=0;
    int participantsAdded = 0; // variable to keep track of number of participants so far added
    int max;

    // Task: Write code for the constructor below to initialize the member variables
    // properly
    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        // write your code here
        this.eventName = eventName;
        this.eventDate = eventDate;
        this.eventLocation = eventLocation;
        max = maximumParticipants;
        registeredStudents = new Student[maximumParticipants];
        waitinglist= new Student[100];
    }

    // Task: Write getters and setters for Event attributes as required
    public String getEventName() {
        return eventName;
    }

    public String getEventDate() {
        return eventDate;
    }

    public String getEventlocation() {
        return eventLocation;
    }

    public void setEventName(String eventName) {
        this.eventName = eventName;
    }

    public void setEventDate(String eventDate) {
        this.eventDate = eventDate;
    }

    public void setEventLocation(String eventLocation) {
        this.eventLocation = eventLocation;
    }

    // Task: Write your code for the function below. This functions adds a
    // participant to this event. Check for the following cases: (i) total
    // participant count does not exceed the maximum participant count, (ii) the
    // studentId is not already added.
    public void addParticipant(Student student) {
        // write your code here
        if (participantsAdded < max) {
            for (int i = 0; i < participantsAdded; i++) {
                if (registeredStudents[i].getId().equals(student.getId())) {
                    System.out.println("participant already added");
                    return;
                }
            }
            registeredStudents[participantsAdded] = student;
            participantsAdded++;
        } else{
            System.out.println("Total participant count for "+eventName+
                "exceeds maximum count. Putting\n" +
                student.getId()+" on waiting list.");
            waitinglist[waiting]=student;
            waiting++;
        }

    }

    // Task: Write code for the function below. This function shows the details of
    // an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here
        System.out.println(" Name: " + eventName + "\n" + " Date: " + eventDate + "\n" + " Location: " + eventLocation
                + "\n" + "Registered Participants:\n");
        for (int i = 0; i < participantsAdded; i++) registeredStudents[i].showDetails();
        System.out.println("Waiting Participants :");
        for(int i=0;i<waiting;i++)waitinglist[i].showDetails();
    }

    // Task: Write code for the function below. This function check whether the
    // studentId in the argument has registered for this event or not. Return true
    // if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        // Write your code here
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getId().equals(studentId)) {
                return true;
            }
        }
        return false;
    }
    public boolean iswaiting(String studentId){
        for (int i = 0; i <waiting; i++) {
            if (waitinglist[i].getId().equals(studentId)) {
                return true;
            }
        }
        return false;
    }
    // Task: Write code for the function below. This function removes a participant
    // from this event. Check for the following cases: (i) the student Id is not
    // regiseterd.
    public void removeParticipant(String studentId) {
        // Write your code here
        if (isRegistered(studentId)) {
            int index = -1;
            for (int i = 0; i < participantsAdded; i++) {
                if (registeredStudents[i].getId().equals(studentId)) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                for (int i = index; i < participantsAdded - 1; i++) {
                    registeredStudents[i].setId(registeredStudents[i + 1].getId());
                    registeredStudents[i].setName(registeredStudents[i + 1].getName());
                }
                System.out.println("Successfully Removed "+studentId+" from event "+eventName);
                participantsAdded--;
            }
        }
        if(iswaiting(studentId))
            registeredStudents[participantsAdded]=waitinglist[0];
            waiting--;
            for(int i=0;i<waiting-1;i++) {
                waitinglist[i].setId(waitinglist[i + 1].getId());
                waitinglist[i].setName(waitinglist[i + 1].getName());
            }
        }

    }


