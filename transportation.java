
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Navigator {
    private TransportBehavior tb;
    private Set<String> supportedTB = new HashSet<>(Arrays.asList("walk", "bus", "car", "bike"));

    public Navigator(TransportBehavior _tb) {
        tb = _tb;
    }

    public Navigator() {
        tb = new WalkTB();
    }

    public void setTB(String type) {
        if (type == null)
            throw new IllegalArgumentException("type can't be null");

        if ( ! supportedTB.contains(type))
            throw new IllegalArgumentException("unsupported transport type");

        if (type.equals("walk"))
            tb = new WalkTB();
        if (type.equals("bus"))
            tb = new BusTB();
        if (type.equals("car"))
            tb = new CarTB();
        if (type.equals("bike"))
            tb = new BikeTB();
    }

    public PathNode getPath(Location A, Location B) {
        return tb.buildPath(A, B);
    }
}