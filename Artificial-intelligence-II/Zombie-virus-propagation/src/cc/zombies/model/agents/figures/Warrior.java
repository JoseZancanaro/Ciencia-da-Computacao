package cc.zombies.model.agents.figures;

/* CC imports */
import cc.zombies.model.agents.figures.base.SimulatedAgent;
import cc.zombies.model.agents.util.Cooldown;
import cc.zombies.model.behaviours.Communicate;
import cc.zombies.model.behaviours.Hunt;
import cc.zombies.model.behaviours.MoveAround;
import cc.zombies.model.behaviours.Sense;
import cc.zombies.model.behaviours.base.SelectiveBehaviour;
import cc.zombies.model.geom.Coordinate;
import cc.zombies.model.geom.Polygon;

/* Java imports */
import java.util.AbstractMap.SimpleEntry;

public class Warrior extends SimulatedAgent {
    public static double DEFAULT_SPEED = 0.00025;

    public Warrior(Polygon bounds, Coordinate coordinate, double speed, double angle,
                    double awarenessRadius, double actionRadius) {
        super("Warrior", bounds, coordinate, speed, angle, awarenessRadius, actionRadius);
    }

    public Warrior(Polygon bounds, Coordinate coordinate, double speed, double angle,
                   double awarenessRadius, double actionRadius, Cooldown senseCooldown,
                   Cooldown commsCooldown, Cooldown skillCooldown) {
        super("Warrior", bounds, coordinate, speed, angle, awarenessRadius, actionRadius,
                senseCooldown, commsCooldown, skillCooldown);
    }

    protected void setup() {
        this.addBehaviour(new Sense(this, this.getSenseCooldown()));
        this.addBehaviour(new Communicate(this, this.getCommsCooldown()));

        this.addBehaviour(new SelectiveBehaviour(this,
                            new SimpleEntry<>(this::hasTarget, new Hunt(this, this.getSkillCooldown())),
                            new SimpleEntry<>(this::hasNoTarget, new MoveAround(this))));
    }

    public boolean hasTarget() {
        return this.getSensed().entrySet().stream().anyMatch(
                (entry) -> SimulatedAgent.getTypeByUuid(entry.getKey()).equalsIgnoreCase("Infected")
                            && Status.LIVE.equals(entry.getValue().getDescription()));
    }

    public boolean hasNoTarget() {
        return !this.hasTarget();
    }
}
