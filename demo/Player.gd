extends CharacterBody2D

#THIS IS CLASS "PLAYER" BODY
const window_size = Vector2(1024, 600)
#var location =Vector2()

var speed = 10000#for fast move to random location
var target_position = Vector2()
var click_position=position#click_position-медленная смена позиции
#THIS IS CLASS FUNC
#THIS FUNC EXECUTE BEFORE ANIMATION
func _ready():
	position=Vector2(randi_range(1, window_size.x), randi_range(1, window_size.y))
	click_position=position
	speed=300
	#rng.randomize()
	#location.x=randi_range(1, window_size.x)
	#location.y=randi_range(1, window_size.y)
	# Set the click position to the player's current position
	speed=speed*randi_range(0, 10)/5 #speed random
func _physics_process(delta):
 
	# This input will need to be created in the input map
	if Input.is_action_just_pressed("left_click"):
		click_position = get_global_mouse_position()
		
	# Check if the player is in a 3px range of the click position, if not move to the target position
	if position.distance_to(click_position) > 3:
		target_position = (click_position - position).normalized()
		velocity = target_position * speed
		move_and_slide()
