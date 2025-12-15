# Gas Abilities 
An experimental project for exploring Unreal Engine's **Gameplay Ability System (GAS)** and advanced code implementations.

**Project Status:** \
✅ *Part 1*: Learning - Complete \
✅ *Part 2*: Advanced - Complete \
📅 *Future integration* - Planned

---

## 📋 Description
GasAbilities is a learning and research project created to explore and master the Gameplay Ability System through practical examples. \
Built in Unreal Engine 5.6 using C++ and Blueprints, the project features a simple testing environment to experiment with various GAS implementations.

## 🎯 Objectives
- Experiment with the Gameplay Ability System
- Test new implementations and code patterns
- Create a reference repository for future GAS implementations
- Build a collection of working examples for practical use

## 💭 Purpose
This repository serves as:
- A personal learning journey through GAS
- A reference for implementing GAS features
- A collection of working examples for future projects
- A resource for others learning GAS

## 🔗 Related Projects
This project is part of a learning series focused on Unreal Engine systems:
- **GasAbilities** (this repo): Gameplay Ability System ✅
  - [GitHub](https://github.com/pittabio/GasAbilities) / [GitLab](https://gitlab.com/pittabio/GasAbilities)
- **StateTreeAI** (in progress): State Trees, AI behaviors, and Quest System 🚧
  - [GitHub](https://github.com/pittabio/StateTreeAI) / [GitLab](https://gitlab.com/pittabio/StateTreeAI)
- **Future Integration** (planned): Full-scale project combining GAS, State Trees, and advanced AI 📅

> 💡 **Learning Path** \
> Each system is mastered in isolation before integration. This approach ensures deep understanding and creates reusable reference implementations.

---

## 🗺️ Project Phases

This project follows a progressive learning path divided into two distinct phases, each building upon the previous one.

### 🎓 Part 1: Fundamentals (`01_Fundamentals/`)
**Focus:** Foundation & Prototyping \
**Status:** Completed ✅

The initial exploration phase where I learned GAS basics through rapid prototyping:
- Separated Abilities and Attributes implementations for focused learning
- Blueprint-heavy approach for quick iteration and experimentation
- Basic Character and Controller hierarchies
- Introduction to Gameplay Tags, Attribute Sets, and simple Abilities
- Dual GameMode setup for isolated testing

**Tech Stack:** ~70% Blueprint, ~30% C++

**Key Achievements**:
- Understanding of ASC (Ability System Component) initialization
- Basic ability granting and activation
- Attribute modification and clamping
- Gameplay tag queries and relationships

### 📚 Part 2: Advanced (`02_Advanced/`)
**Focus:** Deep Dive & Mastery \
**Status:** Completed ✅

**Tech Stack:** ~80% C++, ~20% Blueprint (design iteration only)

**Core Achievements**:
- Scalable and modular architecture patterns
- Production-ready code organization
- Advanced GAS features and best practices
- Performance optimization techniques
- Clean separation of concerns
- Multiple implementation approaches
- Comprehensive HUD integration (mini-map, skill bar, cooldowns, resource display)

> 📂 **Implementation Notes** \
> This phase includes two complete implementations following different tutorial approaches, demonstrating versatility in applying GAS concepts and comparing different architectural patterns.

### 🎮 Future Integration
**Focus:** Full-Scale Implementation \
**Status:** Planned 📅

Future phase where GAS concepts from this project will be combined with State Trees (AI/Quest systems) in a complete game project. \
*Note:* The original "Part 3" concept has evolved. Instead of adding more features to this GAS-focused repository, I'm learning State Trees in a separate project (StateTreeAI). \
A future project will integrate both systems in a production-ready implementation.

**Potential Directions** (to be decided):
- **MMORPG**: Class system, inventory, quests, skill trees, party mechanics
- **MOBA:** Character roster, lane system, jungle camps, team abilities

**Tech Stack:** ~90% C++, ~10% Blueprint (content only)

---

## 📂 Repository Structure

### Branch Organization
This repository documents the entire learning journey through Git branches:

**Main Development:**
- `main`: Stable, production-ready code from all completed phases

> 💡 **Learning Approach** \
> **Part 1** used a branch-per-feature strategy for rapid experimentation and isolated testing. \
> **Part 2** adopted a more structured approach with comprehensive tutorial-based branches.

**Part 1 - Experimental Branches** (Feature Testing): \
These branches represent the iterative learning process during the fundamentals phase:
- `ability/fire-blueprint`, `ability/fireball`: Ability system experiments
- `stats/heal`, `stats/heal-GMMC`, `stats/init`: Attribute and stats testing
- `test/ability-cast-player`, `test/attribute-blueprint`, `test/debug`, `test/simple-ability`: Various GAS feature tests
- `Character`: Character system iterations
- `refactor/character`, `refactor/structure`: Refactor branches to move files and/or folders without using main and breaking something

> 📝 **Note** \
> Experimental branches from Part 1 are kept for documentation purposes and may contain incomplete or outdated code. They represent the learning process, not final implementations.

**Part 2 - Advanced Branches** \
The advanced phase features **two complete implementations** of the same concepts and other features:
- `advanced/ro`, `advanced/kai`: Follow different tutorial approaches to implement advanced GAS features
- `minimap/kibibyte`: Feature branch for minimap functionality

Those implementations are merged in main and demonstrate different valid architectural patterns for production-ready GAS systems.

---

## 🗺️ Progress Overview - Roadmap
```
┌─────────────────────┐     ┌─────────────────────┐     ┌─────────────────────┐
│  Part 1: Basics     │ ──→ │  Part 2: Mastery    │ ──→ │  Future Integration │
├─────────────────────┤     ├─────────────────────┤     ├─────────────────────┤
│ *Completed*         │     │ *Completed*         │     │ *Planned*           │
│ Blueprint Focus     │     │ C++ Deep Dive       │     │ GAS + State Trees   │
│ Separated Systems   │     │ Unified Integration │     │ Complete Game       │
└─────────────────────┘     └─────────────────────┘     └─────────────────────┘
                                                                 ↑
                                                        ┌─────────────────────┐
                                                        │  StateTreeAI        │
                                                        │  (separate project) │
                                                        └─────────────────────┘
```

---

## 🛠️ Technologies
<!-- UNREAL -->
<div>
  <img src="https://skillicons.dev/icons?i=unreal" height="50" alt="unrealengine logo" style="vertical-align: middle;" /> 
  <code>Unreal Engine 5.6</code>
</div>

<!-- RIDER -->
<div>
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/rider/rider-original.svg" height="50" alt="rider logo" style="vertical-align: middle;" />
  <code>JetBrains Rider</code>
</div>

<!-- CODE -->
<div>
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="50" alt="cplusplus logo" style="vertical-align: middle;"  />
  <code>C++</code> <code>Blueprint</code>
</div>

<!-- GIT -->
<div>
  <img src="https://cdn.simpleicons.org/git/F05032" height="50" alt="git logo" style="vertical-align: middle;" /> 
  <code>Git</code> <code>GitKraken Desktop</code>
</div>

---

## 📦 Contents
> 📝 **Note** \
> This section will be updated as the project develops.

### Epic Games
This project includes the following third-party content from **Epic Games**:
- **Third Person Template**: Characters, animations, and related assets from Unreal Engine's Third Person template

All Epic Games content is used under the [Unreal Engine EULA](https://www.unrealengine.com/en-US/eula/unreal) and is subject to Epic Games' licensing terms.

### Mixamo
This project also uses animations from **Mixamo**, a service by Adobe providing free character animations and auto-rigging tools. All Mixamo content is used in accordance with [Adobe’s licensing terms](https://community.adobe.com/t5/mixamo-discussions/mixamo-faq-licensing-royalties-ownership-eula-and-tos/td-p/13234775).

### Kakky
This project uses visual effects from the [**FX Variety Pack**](https://www.fab.com/listings/53531e17-369f-4bba-b493-8588f0dec07b) by [Kakky](https://www.fab.com/sellers/Kakky), a free asset collection available on the [Fab marketplace](https://www.fab.com/). \
All content is used in accordance with Fab's [Standard License](https://www.fab.com/legal/license).

---

## 📚 Learning Resources
> 📝 **Note** \
> Additional resources may be added as the project progresses.

This project is being developed while studying from various sources (_thanks to_):

### Part 1 - Fundamentals
- [Code With Ro](https://www.youtube.com/@CodeWithRo) - YouTube channel with extensive GAS tutorials
- [The Wolf Around](https://www.youtube.com/@TheWolfAround) - YouTube channel, specifically the [Enhanced Input System tutorial](https://www.youtube.com/watch?v=HKX5xJcVDTw)

### Part 2 - Advanced
- [Code With Ro](https://www.youtube.com/@CodeWithRo) - [Ultimate Intro to GAS](https://www.youtube.com/watch?v=Ymxfn1OlNN0) (Ro implementation)
- [Dev Kai](https://www.youtube.com/@DevKaiUnreal) - [Gameplay Ability System - Step by Step](https://www.youtube.com/watch?v=L-3ifQRpyB4) (Kai implementation)
- [Kibibyte](https://www.youtube.com/@kibibytecompany) - Replicated basic minimap [Part 1](https://www.youtube.com/watch?v=HSwDe-2HvFA)

### General Resources
- Unreal Engine Documentation
- Various forums and community resources

---

## 📝 Development Notes
This is a learning project that demonstrates progressive mastery of GAS. 
The repository structure reflects the learning journey:

**Part 1:** Experimental branch-per-feature approach for rapid learning and isolated testing  
**Part 2:** Structured dual-implementation approach comparing different architectural patterns  
**Future:** Integration with State Trees and AI systems in a separate full-scale project

**Current Focus**: GAS learning phase complete. Moving to State Tree mastery in a separate project before final integration.

The code showcases evolution from Blueprint prototyping to production-ready C++ implementations.  \
Feel free to explore the various branches to see the learning progression!

> 🔍 **For Employers/Reviewers** \
> Check `main` branch for the most polished, production-ready code. Experimental branches show the iterative learning process.

---

## 📄 License
This project is protected by copyright. My original code and implementations are licensed for personal, non-commercial use only. 
Third-party content (e.g: Epic Games assets) retains its original licensing. See the [LICENSE](LICENSE) file for complete details.

---

## ❓ FAQ

**Q: Why are there so many branches?** \
A: Part 1 used a branch-per-feature approach for isolated experimentation. Each branch represents a specific GAS concept being learned and tested. This allowed for rapid iteration without affecting other work.

**Q: Which branches should I look at?** \
A: For production-ready code, check the `main` branch. For learning progression, explore the various test and feature branches from Part 1.

**Q: What's the difference between `advanced/ro` and `advanced/kai`?** \
A: Both implement the same advanced GAS concepts but follow different tutorial approaches, demonstrating that multiple valid architectural patterns exist for the same problems.

**Q: What happened to Part 3?** \
A: The original Part 3 concept evolved. Instead of extending this GAS-focused project indefinitely, I'm learning State Trees in a separate project. This keeps each repository focused and creates better reference material. A future project will integrate both systems.

**Q: Is this project abandoned?** \
A: No! The GAS learning phase is complete and the code is production-ready. The focus has shifted to mastering State Trees separately before combining everything in a full-scale project.

---
