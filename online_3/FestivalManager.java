/* This class stores information of a festival which are name, starting date and list of events that will take place during the festival. */
public class FestivalManager {
    private String name;
    private String startDate;
    private Event[] events;
    int eventsAdded = 0;
    int maxev;

    // Task: Write code for the constructor below to initialize the member variables
    // properly
    public FestivalManager(String name, String startDate, int maxEventCount) {
        // write your code here
        this.name = name;
        this.startDate = startDate;
        maxev = maxEventCount;
        events = new Event[maxEventCount];
    }

    // Task: Write code for the function below. This function adds an event to this
    // festival. Check for the following case: (i) total event count does not exceed
    // the maximum number of events allowed for this festival
    public void addEvent(Event e) {
        // write your code here
        if (eventsAdded < maxev) {
            events[eventsAdded] = e;
            System.out.println("Event added successfully!");
            eventsAdded++;
        } else
            System.out.println("events maxed out");
    }

    // Task: Write code for the function below. This function registers a student
    // for an event in this festival. Check for the following case: (i) event does
    // not exist
    public void registerStudent(String eventName, Student s) {
        // Write your code here
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventName().equals(eventName)) {
                events[i].addParticipant(s);
                System.out.println("Student registration completed.");
                return;
            }
        }

        System.out.println("event doesnt exist");

    }

    // Task: Write code for the function below. The function shows the details of
    // this festival. Make sure the output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here
        System.out.println(" Festival Name: " + name + "\n" + " Festival Starting Date: " + startDate + "\n"
                + " Festival Events" + "\n");
        for (int i = 0; i < eventsAdded; i++)
            events[i].showDetails();
    }

    // Task: Write code for the function below. This function shows details of the
    // event in the argument. Check for the following case: (i) event does not exist
    public void showEvent(String eventName) {
        // Write your code here
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventName().equals(eventName)) {
                events[i].showDetails();
                return;
            }
            System.out.println("event doesnt exist");
        }
    }

    // Task: Write code for the function below. This function shows details of the
    // events that will start on the date passed as its argument. Check for the
    // following case: (i) event does not exist
    public void showEventsOnDate(String eventDate) {
        // Write your code here
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventDate().equals(eventDate)) {
                events[i].showDetails();
            }
        }

    }

    // Task: Write code for the function below. This function shows the details of
    // the events with maximum number of participants. If there are multiple events,
    // show all.
    public void eventWithHighestParticipants() {
        // Write your code here
        int max = 1;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].participantsAdded > max)
                max = events[i].participantsAdded;
        }
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].participantsAdded == max) {
                events[i].showDetails();
            }
        }
    }

    // Task: Write code for the function below. This function takes a student Id as
    // input and then lists all the events this particular student has registered
    // for. Make sure your output matches the supplied sample output.
    public void showEventsForStudent(String studentId) {
        // Write your code here
        System.out.println("Student " + studentId + " is registered in :\n");
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].isRegistered(studentId)) {
                System.out.println(events[i].getEventName() + "\n");
            }
            if(events[i].iswaiting(studentId)){
                System.out.println("Student " + studentId + " is waiting in :\n");
                System.out.println(events[i].getEventName() + "\n");
            }
        }
    }

    // Task: Write code for the function below. This functions takes an event's name
    // and a student's ID as arguments and then removes the student from the
    // registered student list of the event. Check for the following cases: (i)
    // event does not exist, (ii) student is not registered for the event
    public void cancelRegistration(String eventName, String studentId) {
        // Write your code here
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventName().equals(eventName)) {
                events[i].removeParticipant(studentId);
                return;
            }
        }
        System.out.println("event doesnt exist");
    }
}
